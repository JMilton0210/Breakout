#pragma once
#include "Particle.h"
#include "MyMath.cpp"

class ExplosionParticle : public Particle
{

	sf::Vector2f _direction;
	float _acceleration;

	float _radius_max;
	float _radius_min;

	sf::Color _color_a;
	sf::Color _color_b;
	float _color_speed;
	float _color_time;

	void CreateParticle() override;
	void UpdateParticle(float dt) override;
	void DestroyParticle() override;

};

