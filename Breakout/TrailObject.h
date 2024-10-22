#pragma once
#include <SFML/Graphics.hpp>

class TrailObject
{
private:
	
	float _radius = 15;
	float _timer;

public:
	sf::CircleShape _sprite;
	TrailObject();
	void Spawn(float duration, sf::Vector2f position);
	bool Update(float dt);
};

