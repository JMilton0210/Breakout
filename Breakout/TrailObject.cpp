#include "TrailObject.h"

TrailObject::TrailObject()
{
	_sprite.setFillColor(sf::Color::White);
	_sprite.setRadius(_radius);
	_sprite.setPosition(sf::Vector2f(0, 0));
	_timer = 1;
}

void TrailObject::Spawn(float duration, sf::Vector2f position)
{
	_timer = duration;
	_sprite.setPosition(position);
}

bool TrailObject::Update(float dt)
{
	_timer -= dt;
	_sprite.setRadius(_radius * _timer);
	if (_timer > 0) 
		return false;
	return true;
}
