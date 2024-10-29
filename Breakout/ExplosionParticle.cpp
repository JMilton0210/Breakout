#include "ExplosionParticle.h"

void ExplosionParticle::CreateParticle()
{
	_direction = MyMath::RandomUnitVector();
	int _speed = rand()%200  ;
	_direction.x *= _speed;
	_direction.y *= _speed;
	_acceleration = 500;
}
void ExplosionParticle::UpdateParticle(float dt)
{
	_sprite.setPosition(_sprite.getPosition() + (_direction * dt));
	_direction.y += (_acceleration * dt);
}

void ExplosionParticle::DestroyParticle()
{
}
