#pragma once
#include <SFML/Graphics.hpp>

class Particle
{
	bool _active;
	float _time_limit;
	float _time_elapsed;
	sf::CircleShape _sprite;

public:
	
	bool IsActive();

	void Create(float _lifetime_in_seconds, float _size, sf::Vector2f _position);
	void Destroy();

	void Update(float dt);
	void Render(sf::RenderWindow* _renderer);
};

