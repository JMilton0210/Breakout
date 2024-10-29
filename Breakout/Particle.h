#pragma once
#include <SFML/Graphics.hpp>

class Particle
{
protected:
	bool _active;
	float _time_limit;
	float _time_elapsed;
	sf::CircleShape _sprite;
	

public:
	virtual void UpdateParticle(float dt) {};
	virtual void CreateParticle() {};
	virtual void DestroyParticle() {};

	bool IsActive();

	void Create(float _lifetime_in_seconds, float _size, sf::Vector2f _position);
	void Destroy();

	void Update(float dt);
	void Render(sf::RenderWindow* _renderer);
};

