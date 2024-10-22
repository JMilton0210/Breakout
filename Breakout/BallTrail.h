#pragma once
#include <vector>
#include "TrailObject.h"

class BallTrail
{
private:
	
	//Timers
	float _timerCurrent;
	float _timerLimit = 0.05f;
	bool _flag = false;

	//Trail Objects
	float _trailDuration = 0.5f;
	const int _trailSize = 16;
	std::vector<bool> _trailActive;
	std::vector<TrailObject> _trailObject;

	bool CheckTimer();
	int FirstInactiveTrail();
	void SpawnTrail(sf::Vector2f ballPosition);

public:
	BallTrail();
	void Update(float dt, sf::Vector2f ballPosition);
	void Render(sf::RenderWindow* _window);

};

