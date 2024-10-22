#include "BallTrail.h"

BallTrail::BallTrail() {
	_timerCurrent = 0;
	_flag = false;

	for (int i = 0; i < _trailSize; i++) {
		_trailActive.push_back(false);
		_trailObject.push_back(TrailObject());
	}
}

bool BallTrail::CheckTimer()
{
	if (!_flag) return false;

	_flag = false;
	return true;
}

int BallTrail::FirstInactiveTrail()
{
	for (int i = 0; i < _trailSize; i++) {
		if (!_trailActive[i]) return i;
	}
	return -1;
}

void BallTrail::SpawnTrail(sf::Vector2f ballPosition)
{
	int slot = FirstInactiveTrail();
	if (slot == -1) return;
	_trailObject[slot].Spawn(_trailDuration, ballPosition);
	_trailActive[slot] = true;
}

void BallTrail::Update(float dt, sf::Vector2f ball_position)
{
	_timerCurrent += dt;
	if (_timerCurrent >= _timerLimit) {
		_timerCurrent -= _timerLimit;
		_flag = true;
	}
	if (CheckTimer()) {
		SpawnTrail(ball_position);
	}

	//Update Trail Objects
	for (int i = 0; i < _trailSize; i++) {
		if (_trailActive[i])
			if (_trailObject[i].Update(dt))
				_trailActive[i] = false;
	}
}

void BallTrail::Render(sf::RenderWindow* _window)
{
	for (int i = 0; i < _trailSize; i++) {
		if(_trailActive[i])
			_window->draw(_trailObject[i]._sprite);
	}
}



