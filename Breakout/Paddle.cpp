#include "Paddle.h"
#include <iostream>

Paddle::Paddle(sf::RenderWindow* window)
    : _window(window), _width(PADDLE_WIDTH), _timeInNewSize(0.0f), _isAlive(true)
{
    _height = window->getSize().y - 50.0f;
    _sprite.setFillColor(sf::Color::Cyan);
    _sprite.setPosition((window->getSize().x - _width) / 2.0f, _height);
    _sprite.setSize(sf::Vector2f(_width, PADDLE_HEIGHT));
    _sprite.setOutlineColor(sf::Color::Cyan);
    _sprite.setOutlineThickness(0);
}

Paddle::~Paddle()
{
}

void Paddle::moveLeft(float dt)
{
    float position = _sprite.getPosition().x;

    if (position > 0)
    {
        _sprite.move(sf::Vector2f(-dt * PADDLE_SPEED, 0));
    }
}

void Paddle::moveRight(float dt)
{
    float position = _sprite.getPosition().x;

    if (position < _window->getSize().x - _width)
    {
        _sprite.move(sf::Vector2f(dt * PADDLE_SPEED, 0));
    }
}

void Paddle::moveTo(float dt, float desiredX)
{
    // Offset Desired Position for sprite size
    desiredX -= 550;   
    _sprite.setPosition(sf::Vector2f(desiredX, _height));
    
    // Alternate Control Scheme (Thats Feels Worse)
    //float position = _sprite.getPosition().x;
    //if (position > desiredX) _sprite.move(sf::Vector2f(-dt * PADDLE_SPEED, 0));
    //if (position < desiredX) _sprite.move(sf::Vector2f(dt * PADDLE_SPEED, 0));
}

void Paddle::update(float dt)
{
    UpdateCollisionResponse(dt);
    if (_timeInNewSize > 0)
    {
        _timeInNewSize -= dt;
    }
    else
    {
        setWidth(1.0f, 0.0f); // Reset to default width after duration
    }
}

void Paddle::render()
{
    _window->draw(_sprite);
}

sf::FloatRect Paddle::getBounds() const
{
    return _sprite.getGlobalBounds();
}

// update width by SF of coeff. 
// ensure centre remains consistent.
void Paddle::setWidth(float coeff, float duration)
{
    _width = coeff * PADDLE_WIDTH;
    _sprite.setSize(sf::Vector2f(_width, _sprite.getSize().y));
    _timeInNewSize = duration;
    float newX = _sprite.getPosition().x + (_width - PADDLE_WIDTH) / 2;
    _sprite.setPosition(newX, _sprite.getPosition().y);
}

void Paddle::CollisionWithBall()
{
    _collisionFlag = true;
}

void Paddle::UpdateCollisionResponse(float dt)
{
    if (_collisionFlag) {
        _timerCurrent += dt;
        if (_timerCurrent > _timerLimit) {
            _timerCurrent -= _timerLimit;
            _collisionFlag = false;
        }
        //Calculate Colour
        float coeff = _timerCurrent / _timerLimit;
        if (coeff > 1) coeff = 1;
        float r = lerp(_collisionColour.r, sf::Color::Cyan.r, coeff);
        float g = lerp(_collisionColour.g, sf::Color::Cyan.g, coeff);
        float b = lerp(_collisionColour.b, sf::Color::Cyan.b, coeff);
        _sprite.setFillColor(sf::Color(r,g,b));
    }
    else {
        _sprite.setFillColor(sf::Color::Cyan);
    }
}

float Paddle::lerp(float a, float b, float t)
{
    return (1.0f - t) * a + b * t;
}
