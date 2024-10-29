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
    _shape.setPosition(_shape.getPosition() + vec);
}

void Brick::render(sf::RenderWindow& window)
{
    if (!_isDestroyed) {
        window.draw(_shape);
    }
    explosion.Render(&window);
}

sf::FloatRect Brick::getBounds() const
{
    return _shape.getGlobalBounds();
}

bool Brick::GetDestroyed()
{
    return _isDestroyed;
}

void Brick::SetDestroyed(bool arg_destroyed)
{
    _isDestroyed = arg_destroyed;
}

void Brick::StartExplosion()
{
    sf::Vector2f _pos = _shape.getPosition();
    _pos.x += _shape.getSize().x / 2;
    _pos.y += _shape.getSize().y / 2;
    explosion.Create(200, 2, 1, _pos);
}

void Brick::UpdateExplosion(float dt)
{
    explosion.Update(dt);
}
