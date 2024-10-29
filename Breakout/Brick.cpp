#include "Brick.h"

Brick::Brick(float x, float y, float width, float height)
    : _isDestroyed(false)
{
    _shape.setPosition(x, y);
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(sf::Color::Red);
}

void Brick::move(sf::Vector2f vec)
{
    if(!_isDestroyed)
        _shape.setPosition(_shape.getPosition() + vec);
}

void Brick::render(sf::RenderWindow& window)
{
    if (!_isDestroyed) {
        window.draw(_shape);
    }
}

sf::FloatRect Brick::getBounds() const
{
    return _shape.getGlobalBounds();
}

bool Brick::GetDestroyed()
{
    return _isDestroyed;
}

void Brick::SetDestroyed(bool _d)
{
    _isDestroyed = _d;
}
