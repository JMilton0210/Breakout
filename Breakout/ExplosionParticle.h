#pragma once
#include "Particle.h"
#include "MyMath.cpp"

class ExplosionParticle : public Particle
{
	
	sf::Vector2f _direction;
	float _acceleration;

	void CreateParticle() override; 
	void UpdateParticle(float dt);
	void DestroyParticle() override;
	

public:
	
};

