#include "HighscoreData.h"

std::string HighscoreData::GetStringFromScore(Score arg_score)
{
    return arg_score.name + " :\t" + std::to_string(arg_score.time);

}

void HighscoreData::Initialise()
{
    for (int i = 0; i < _numofscores; i++) {
        _highscores[i].name = "Score";
        _highscores[i].time = i + 1;
    }
}

std::string HighscoreData::ScoreString(int i)
{
    return GetStringFromScore(_highscores[i]);
}
