#pragma once

#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"

class Paddle
{
public:
    Paddle(sf::RenderWindow* window);
    ~Paddle();

    void moveLeft(float dt);
    void moveRight(float dt);
    void moveTo(float dt, float desiredX);
    void update(float dt);
    void render();
    sf::FloatRect getBounds() const;
    void setWidth(float coeff, float duration);

    void CollisionWithBall();
    void UpdateCollisionResponse(float dt);
    static float lerp(float a, float b, float t);

private:


    sf::RenderWindow* _window;
    sf::RectangleShape _sprite;
    float _width = PADDLE_WIDTH;
    bool _isAlive;
    float _timeInNewSize = 0.0f;
    float _height;

    bool _collisionFlag = false;
    sf::Color _collisionColour = sf::Color::Red;
    float _timerCurrent = 0;
    float _timerLimit = 0.25f;
};
