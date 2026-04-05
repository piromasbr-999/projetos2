#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>

const int WIDTH = 160;
const int HEIGHT = 80;

struct Vec3 {
    float x, y, z;
};

Vec3 rotateY(Vec3 v, float angle) {
    return {
        v.x * cos(angle) - v.z * sin(angle),
        v.y,
        v.x * sin(angle) + v.z * cos(angle)
    };
}

Vec3 rotateX(Vec3 v, float angle) {
    return {
        v.x,
        v.y * cos(angle) - v.z * sin(angle),
        v.y * sin(angle) + v.z * cos(angle)
    };
}

Vec3 project(Vec3 v) {
    float distance = 3.0;
    float factor = distance / (distance + v.z);
    return {
        v.x * factor,
        v.y * factor,
        v.z
    };
}

// Desenhar linha
void drawLine(int x1, int y1, int x2, int y2, char screen[HEIGHT][WIDTH]) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int steps = std::max(dx, dy);

    float xInc = (x2 - x1) / (float)steps;
    float yInc = (y2 - y1) / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        int xi = (int)x;
        int yi = (int)y;

        if (xi >= 0 && xi < WIDTH && yi >= 0 && yi < HEIGHT)
            screen[yi][xi] = '#';

        x += xInc;
        y += yInc;
    }
}

int main() {
    std::vector<Vec3> vertices = {
        {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
        {-1, -1,  1}, {1, -1,  1}, {1, 1,  1}, {-1, 1,  1}
    };

    // Arestas do cubo
    std::vector<std::pair<int,int>> edges = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    float angle = 0;

    while (true) {
        char screen[HEIGHT][WIDTH];

        // limpa
        for (int y = 0; y < HEIGHT; y++)
            for (int x = 0; x < WIDTH; x++)
                screen[y][x] = ' ';

        // armazenar pontos projetados
        std::vector<std::pair<int,int>> projected;

        for (auto v : vertices) {
            v = rotateY(v, angle);
            v = rotateX(v, angle * 0.5);

            Vec3 p = project(v);

            int x = (p.x + 1) * WIDTH / 2;
            int y = (p.y + 1) * HEIGHT / 2;

            projected.push_back({x, y});
        }

        // desenhar arestas
        for (auto e : edges) {
            auto p1 = projected[e.first];
            auto p2 = projected[e.second];

            drawLine(p1.first, p1.second, p2.first, p2.second, screen);
        }

        std::cout << "\x1b[H";

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                std::cout << screen[y][x];
            }
            std::cout << "\n";
        }

        angle += 0.05;
        usleep(30000);
    }

    return 0;
}