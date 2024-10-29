#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleCluster.h"
#include "ExplosionParticle.h"


class GameManager;  // forward declaration



class Ball {
public:
    Ball(sf::RenderWindow* window, float velocity, GameManager* gameManager);
    ~Ball();
    void update(float dt);
    void render();
    void setVelocity(float coeff, float duration);
    void setFireBall(float duration);
    void testBounce();
    sf::Vector2f GetPosition();

private:
    void IncreaseSpeed();
    sf::CircleShape _sprite;
    sf::Vector2f _direction;
    sf::RenderWindow* _window;
    float _velocity;
    float _velocityInitial;
    float _velocityCumulative;
    bool _isAlive;
    bool _isFireBall;
    float _timeWithPowerupEffect;

    GameManager* _gameManager;  // Reference to the GameManager

    float _trail_timer = 0.0f;
    float _trail_limit = 0.1f;
    std::vector<ParticleCluster<ExplosionParticle>> cluster_array;


    static constexpr float RADIUS = 10.0f;      
    static constexpr float VELOCITY = 350.0f;   // for reference.
};

