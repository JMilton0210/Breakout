#include "Particle.h"

bool Particle::IsActive()
{
	return _active;
}
float Particle::GetTime() 
{
	return _time_elapsed / _time_limit;
}

void Particle::Create(float _lifetime, float _size, sf::Vector2f _pos)
{
	_active = true;
	_time_elapsed = 0;
	_time_limit = _lifetime;
	_sprite.setRadius(_size);
	_sprite.setPosition(_pos);
	CreateParticle();
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

void Particle::Render(sf::RenderWindow* _window)
{
	if (_active) {
		_window->draw(_sprite);
	}
}

void Particle::Destroy()
{
	_active = false;
	DestroyParticle();
}
