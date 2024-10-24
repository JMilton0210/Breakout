#include "HighscoreData.h"

std::string HighscoreData::GetStringFromScore(Score arg_score)
{
    return arg_score.name + " : " + std::to_string(arg_score.time);

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

int HighscoreData::GetValidScores()
{
    return _validscores;
}

void HighscoreData::AddScore(std::string arg_name, float arg_time)
{
    Score newScore = Score(arg_name, 0, arg_time);

    //Create Temporary copy of the highscore list
    std::vector<Score> temp(6);
    int i = 0;
    while (i < _validscores) {
        temp[i] = _highscores[i];
        i++;
    }

    //Add new score to list
    temp[i] = newScore;

    //Limit Max number of scores to 5
    if (_validscores < 5) _validscores++;

    //Sort the list based on shortest time
    std::sort(temp.begin(), temp.end(), [](const Score& a, const Score& b) {
        return a.time < b.time;
        });

    // Set Highscore List to Sorted List and remove the last element if oversized
    for (int i = 0; i < _validscores; i++) {
        _highscores[i] = temp[i];
    }


}
