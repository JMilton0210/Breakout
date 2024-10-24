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

		Score() {};
		Score(std::string _name, int _bounces, float _time)
		{
			name = _name; bounces = _bounces; time = _time;
		}
	};

	int _validscores = 0;
	int _numofscores = 5;
	Score _highscores[5];
	
	bool is_lower(const Score& a, const Score& b);
	std::string GetStringFromScore(Score arg_score);
	void sort(std::vector<Score>& arr);

public:
	
	void Initialise();
	std::string ScoreString(int i);
	int GetValidScores();
	void AddScore(std::string arg_name, float arg_time);
};

