#include <SFML/Graphics.hpp>

int main() {
    // 1. Criar a janela
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Funcional");

    // 2. Loop principal
    while (window.isOpen()) {
        // 3. Processar eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 4. Renderizar
        window.clear(sf::Color::Red);
        // Desenhe seus objetos aqui (ex: window.draw(shape);)
        window.display();
    }
    return 0;
}
