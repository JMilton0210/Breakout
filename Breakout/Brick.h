#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleCluster.h"
#include "ExplosionParticle.h"

class Brick {
public:
    Brick(float x, float y, float width, float height);
    void move(sf::Vector2f vec);
    void render(sf::RenderWindow& window);
    
    sf::FloatRect getBounds() const;
    bool GetDestroyed();
    void SetDestroyed(bool _d);


    void StartExplosion();
    void UpdateExplosion(float dt);
    ParticleCluster<ExplosionParticle> explosion;

private:
    sf::RectangleShape _shape;
    bool _isDestroyed;
};