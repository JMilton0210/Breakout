#pragma once
#include <vector>
#include "Brick.h"
#include <SFML/Graphics.hpp>

class GameManager;

class BrickManager {
public:
    BrickManager(sf::RenderWindow* window, GameManager* gameManager);
    void createBricks(int rows, int cols, float brickWidth, float brickHeight, float spacing);
    void update(float dt);
    void render();
    int checkCollision(sf::CircleShape& ball, sf::Vector2f& direction);

private:
    std::vector<Brick> _bricks;
    sf::RenderWindow* _window;

    GameManager* _gameManager;
    static constexpr float TOP_PADDING = 100.0f;

    // Movement Data
    bool _moveFlag = false;
    float _speedX = 10;
    float _distY = 0;
    // Movement Timers
    float _moveTimer = 5;
    float _moveLimit = 10;


};
