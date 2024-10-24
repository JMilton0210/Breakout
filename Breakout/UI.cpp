#include <sstream>

#include "UI.h"
#include "GameManager.h"
#include <iomanip>

UI::UI(sf::RenderWindow* window, int lives, GameManager* gameManager) 
	: _window(window), _gameManager(gameManager)
{
	reset_lives(lives);

	_powerupText.setCharacterSize(30);
	_powerupText.setPosition(850, 700);
	_powerupText.setFillColor(sf::Color::Cyan);
	_font.loadFromFile("font/montS.ttf");
	_powerupText.setFont(_font);

	//PowerUp Bar
	_bar.setPosition(950,700);
	_bar.setFillColor(sf::Color::White);
	_bar.setSize(sf::Vector2f(10, 200));
	_bar.setScale(sf::Vector2f(1, -1));
	_barBack.setPosition(950, 700);
	_barBack.setSize(sf::Vector2f(10, 200));
	_barBack.setScale(sf::Vector2f(1, -1));
	_barBack.setFillColor(sf::Color::White);
	_barBack.setOutlineColor(sf::Color::Cyan);
	_barBack.setOutlineThickness(3);

	//Highscore Text
	for (int i = 0; i < _numOfScores; i++) {
		_highscoreText[i].setCharacterSize(30);
		_highscoreText[i].setPosition(800, 50 + (i*40));
		_highscoreText[i].setFillColor(sf::Color::White);
		_highscoreText[i].setFont(_font);
		_highscoreText[i].setString("lick");
		
		_highscoreGrid[i].setPosition(800, 50 + (i * 40));
		_highscoreGrid[i].setSize(sf::Vector2f(180, 40));
		if (i % 2 == 0) _highscoreGrid[i].setFillColor(sf::Color(200, 200, 250, 150));
		else _highscoreGrid[i].setFillColor(sf::Color(200, 250, 200, 150));
	}
	_highscoreData.Initialise();

}

UI::~UI()
{
}


void UI::updatePowerup(std::pair<POWERUPS, float> powerup)
{
	std::ostringstream oss;
	_barActive = true;

	switch (powerup.first)
	{
	case bigPaddle:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("big " + oss.str());
		_powerupText.setFillColor(paddleEffectsColour);
		_bar.setFillColor(paddleEffectsColour);
		break;
	case smallPaddle:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("small " + oss.str());
		_powerupText.setFillColor(paddleEffectsColour);
		_bar.setFillColor(paddleEffectsColour);
		break;
	case slowBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("slow " + oss.str());
		_powerupText.setFillColor(ballEffectsColour);
		_bar.setFillColor(ballEffectsColour);
		break;
	case fastBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("fast " + oss.str());
		_powerupText.setFillColor(ballEffectsColour);
		_bar.setFillColor(ballEffectsColour);
		break;
	case fireBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString("fire " + oss.str());
		_powerupText.setFillColor(extraBallEffectsColour);
		_bar.setFillColor(extraBallEffectsColour);
		break;
	case none:
		_powerupText.setString("");
		_barActive = false;
		break;
	}

	_bar.setScale(1, -0.2 * powerup.second);

}

void UI::reset_lives(int lives)
{
	for (int i = lives; i > 0; --i)
	{
		sf::CircleShape newLife;
		newLife.setFillColor(sf::Color::Red);
		newLife.setOutlineColor(sf::Color::Cyan);
		newLife.setOutlineThickness(4.0f);
		newLife.setRadius(LIFE_RADIUS);
		newLife.setPosition((LIFE_RADIUS * 2 + LIFE_PADDING) * i, LIFE_PADDING);
		_lives.push_back(newLife);
	}
}

void UI::lifeLost(int lives)
{
	_lives[_lives.size() - 1 - lives].setFillColor(sf::Color::Transparent);
}

void UI::addscore(std::string arg_string, float arg_time)
{
	_highscoreData.AddScore(arg_string, arg_time);
}

void UI::render()
{
	_window->draw(_powerupText);
	if (_barActive) {
		_window->draw(_barBack);
		_window->draw(_bar);
	}
	for (sf::CircleShape life : _lives)
	{
		_window->draw(life);
	}
	for (int i = 0; i < _highscoreData.GetValidScores(); i++) {
		_highscoreText[i].setString(_highscoreData.ScoreString(i));
		_window->draw(_highscoreGrid[i]);
		_window->draw(_highscoreText[i]);
	}
}