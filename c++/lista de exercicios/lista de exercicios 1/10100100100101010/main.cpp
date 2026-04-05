#include <iostream>
#include <random>
#include <thread>
#include <chrono>
using namespace std;

int main() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 1);

    while (true) {

        // imprime uma linha com 30 bits
        for (int i = 0; i < 10000; i++) {
            cout << dist(gen);
        }

        cout << "\n";

        // pequeno delay (velocidade)
        this_thread::sleep_for(chrono::milliseconds(1));
    }

    return 0;
}