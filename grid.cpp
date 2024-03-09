#include <SFML/Graphics.hpp>

void drawSquare(sf::RenderWindow& window, const sf::Vector2f& position, float size) {
    sf::RectangleShape square(sf::Vector2f(size, size));
    square.setFillColor(sf::Color::White);
    square.setPosition(position);
    window.draw(square);
}

void drawSquareGrid(sf::RenderWindow& window, const sf::Vector2f& position, float size, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sf::Vector2f squarePosition = position + sf::Vector2f(j * size, i * size);
            drawSquare(window, squarePosition, size);
        }
    }
}

void drawing(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Square Grid Example");

    sf::Vector2f baseSquarePosition(100, 100);
    float baseSquareSize = 30;
    int rows = 10;
    int cols = 10;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawSquareGrid(window, baseSquarePosition, baseSquareSize, rows, cols);
        window.display();
    }

    return 0;
}
