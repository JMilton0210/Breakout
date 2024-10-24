#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
	_currentState = Play;
}

GameStateManager::GameStateManager(GameManager* arg_gameManager)
{
	_currentState = Play;
	_game = arg_gameManager;
}

void GameStateManager::update(float dt)
{
	switch (_currentState) {
	case None: HandleNone(dt); break;
	case Play: HandlePlay(dt); break;
	case Pause: HandlePause(dt); break;
	case Win: HandleWin(dt); break;
	case Lose: HandleLose(dt); break;
	}
}

GameState GameStateManager::GetCurrentState()
{
	return _currentState;
}

void GameStateManager::SetCurrentState(GameState arg_state)
{
	_currentState = arg_state;
}

void GameStateManager::HandleNone(float dt)
{
}

void GameStateManager::HandlePlay(float dt)
{
	_game->update(dt);
}

void GameStateManager::HandlePause(float dt)
{
}

void GameStateManager::HandleWin(float dt)
{
}

void GameStateManager::HandleLose(float dt)
{
}
