#include "Particle.h"

bool Particle::IsActive()
{
	return _active;
}

void Particle::Create(float _lifetime_in_seconds, float _size, sf::Vector2f _position)
{
	_active = true;
	_time_elapsed = 0; 
	_time_limit = _lifetime_in_seconds;
	_sprite.setRadius(_size);
	_sprite.setPosition(_position);
	CreateParticle();
}
void Particle::Destroy()
{
	_active = false;
	DestroyParticle();
}

void Particle::Update(float dt)
{
	if (_active) {
		_time_elapsed += dt;
		if (_time_elapsed >= _time_limit) {
			Destroy();
		}
		UpdateParticle(dt);
	}
}

void Particle::Render(sf::RenderWindow* _renderer)
{
	if (_active)
		_renderer->draw(_sprite);
}


