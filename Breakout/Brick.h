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
    void SetDestroyed(bool);

    void StartExplosion();
    void UpdateExplosion(float dt);

private:
    sf::RectangleShape _shape;
    bool _isDestroyed;

    ParticleCluster<ExplosionParticle> explosion;
};