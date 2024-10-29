#pragma once
#include <vector>
#include "Particle.h"

template <typename ParticleType>
class ParticleCluster
{
	std::vector<ParticleType> particles;

public: 

	bool IsActive();

	void Create( int _particle_count, float _lifetime_in_seconds, float _size, sf::Vector2f _position);
	void Update(float dt);
	void Render(sf::RenderWindow* _window);

};

template<typename ParticleType>
inline bool ParticleCluster<ParticleType>::IsActive()
{
	for (int i = 0; i < particles.size(); i++) {
		if (particles[i].IsActive())
			return true;
	}
	return false;
}

template<typename ParticleType>
inline void ParticleCluster<ParticleType>::Create(int _particle_count, float _lifetime_in_seconds, float _size, sf::Vector2f _position)
{
	particles = std::vector<ParticleType>(_particle_count);
	for (int i = 0; i < particles.size(); i++) {
		particles[i].Create(_lifetime_in_seconds, _size, _position);
	}
}

template<typename ParticleType>
inline void ParticleCluster<ParticleType>::Update(float dt)
{
	for (int i = 0; i < particles.size(); i++) {
		particles[i].Update(dt);
	}
}

template<typename ParticleType>
inline void ParticleCluster<ParticleType>::Render(sf::RenderWindow* _window)
{
	for (int i = 0; i < particles.size(); i++) {
		particles[i].Render(_window);
	}
}
