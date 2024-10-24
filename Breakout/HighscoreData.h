#pragma once
#include <string>

class HighscoreData
{
	struct Score {
		std::string name = "";
		int bounces = 0;
		float time = 0;

		Score() {};
		Score(std::string _name, int _bounces, float _time)
		{
			name = _name; bounces = _bounces; time = _time;
		}
	};

	int _numofscores = 5;
	Score _highscores[5];

	std::string GetStringFromScore(Score arg_score);

public:
	
	void Initialise();
	std::string ScoreString(int i);
};

