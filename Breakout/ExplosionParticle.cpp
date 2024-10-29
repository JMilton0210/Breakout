#include "ExplosionParticle.h"

void ExplosionParticle::CreateParticle()
{
	_direction = MyMath::RandomUnitVector();
	_direction.x *= 2;
	_speed = 300;
	_acceleration = 4;
}
void ExplosionParticle::UpdateParticle(float dt)
{
	_sprite.setPosition(_sprite.getPosition() + (_speed * _direction * dt));
	_direction.y += (_acceleration * dt);
}

void ExplosionParticle::DestroyParticle()
{
}
