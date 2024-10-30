#pragma once
#include <SFML/Graphics.hpp>

class Particle
{

protected:
	sf::CircleShape _sprite;
	bool _active;
	float _time_elapsed;
	float _time_limit;

public:
	bool IsActive();
	float GetTime();

	void Create(float __lifetime, float _size, sf::Vector2f _pos);
	void Update(float dt);
	void Render(sf::RenderWindow* _window);
	void Destroy();

	virtual void UpdateParticle(float dt) {};
	virtual void CreateParticle() {};
	virtual void DestroyParticle() {};

};
