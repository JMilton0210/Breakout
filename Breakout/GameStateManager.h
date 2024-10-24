#pragma once
#include "GameManager.h"

enum GameState { None, Play, Pause, Win, Lose };
class GameStateManager
{
public:
	GameStateManager();
	GameStateManager(GameManager* arg_gameManager);
	void update(float dt);
	
	GameState GetCurrentState();
	void SetCurrentState(GameState arg_state);

private:
	GameState _currentState;
	GameManager* _game;

	void HandleNone(float dt);
	void HandlePlay(float dt);
	void HandlePause(float dt);
	void HandleWin(float dt);
	void HandleLose(float dt);

};

