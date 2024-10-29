#include "ExplosionParticle.h"

void ExplosionParticle::CreateParticle()
{
	// MOVEMENT
	_direction = MyMath::RandomUnitVector();
	int _speed = rand()%200  ;
	_direction.x *= _speed;
	_direction.y *= _speed;
	_acceleration = 500;

	// SIZE
	_radius_max = _sprite.getRadius();
	_radius_min = 0;

	// COLOUR
	_color_time = 0;
	_color_speed = rand()%100;
	_color_speed *= 1.0f / 3.0f;
	_color_a = MyMath::RandomColor();
	_color_b = MyMath::RandomColor();
	
}
void ExplosionParticle::UpdateParticle(float dt)
{
	// MOVEMENT
	_sprite.setPosition(_sprite.getPosition() + (_direction * dt));
	_direction.y += (_acceleration * dt);

	// SIZE
	_sprite.setRadius(MyMath::lerp(GetTime(), _radius_max, _radius_min));

	// COLOR
	_color_time += dt * _color_speed;
	if (_color_time >= 1) {
		_color_time -= 1;
		_color_a = _color_b;
		_color_b = MyMath::RandomColor();
	}
	_sprite.setFillColor(MyMath::LerpColor(_color_time, _color_a, _color_b));
}

void ExplosionParticle::DestroyParticle()
{
}
