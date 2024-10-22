#pragma once
#include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(float x, float y, float width, float height);
    void move(sf::Vector2f vec);
    void render(sf::RenderWindow& window);
    
    sf::FloatRect getBounds() const;
    bool GetDestroyed();

private:
    sf::RectangleShape _shape;
    bool _isDestroyed;
};