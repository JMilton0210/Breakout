#include <sstream>

#include "UI.h"
#include "GameManager.h"
#include <iomanip>

UI::UI(sf::RenderWindow* window, int lives, GameManager* gameManager) 
	: _window(window), _gameManager(gameManager)
{
	for (int i = lives; i > 0; --i)
	{
		sf::CircleShape newLife;
		newLife.setFillColor(sf::Color::Red);	
		newLife.setOutlineColor(sf::Color::Cyan);
		newLife.setOutlineThickness(4.0f);
		newLife.setRadius(LIFE_RADIUS);
		newLife.setPosition((LIFE_RADIUS*2 + LIFE_PADDING) * i, LIFE_PADDING);
		_lives.push_back(newLife);
	}
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

void UI::lifeLost(int lives)
{
	_lives[_lives.size() - 1 - lives].setFillColor(sf::Color::Transparent);
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
}