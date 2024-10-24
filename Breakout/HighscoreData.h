#pragma once
#include <string>
#include <algorithm>
#include <vector>

class HighscoreData
{
	struct Score {
		std::string name = "";
		int bounces = 0;
		float time = 10000;
		int score = 0;

		Score() {};
		Score(std::string _name, int _bounces, float _time, float _score)
		{
			name = _name; bounces = _bounces; time = _time; score = _score;
		}
	};

	int _validscores = 0;
	int _numofscores = 5;
	Score _highscores[5];
	
	std::string GetStringFromScore(Score arg_score);

public:
	
	void Initialise();
	std::string ScoreString(int i);
	int GetValidScores();
	void AddScore(std::string arg_name, float arg_time);
	static int GetScoreFromTime(float _time);
};

