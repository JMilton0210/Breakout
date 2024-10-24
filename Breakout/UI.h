#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "CONSTANTS.h"
#include "PowerupManager.h"

#include "HighscoreData.h"

class GameManager;

class UI
{
public:
	UI(sf::RenderWindow* window, int lives, GameManager* gameManager);
	~UI();

	void updatePowerup(std::pair<POWERUPS, float>);
	void reset_lives(int lives);
	void lifeLost(int lives);
	void addscore(std::string arg_string, float arg_time);
	void render();

private:
	GameManager* _gameManager;
	
	sf::RenderWindow* _window;
	sf::Font _font;
	sf::Text _powerupText;

	std::vector<sf::CircleShape> _lives;

	static constexpr float LIFE_RADIUS = 15.0f;
	static constexpr float LIFE_PADDING = 20.0f;

	bool _barActive = false;
	sf::RectangleShape _bar;
	sf::RectangleShape _barBack;

	int _numOfScores = 5;
	sf::Text _highscoreText[5];
	sf::RectangleShape _highscoreGrid[5];
	HighscoreData _highscoreData;
	
};

