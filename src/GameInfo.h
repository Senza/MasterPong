#include "enums.hpp"
#include "Ball.h"

class GameInfo
{
private:
    GameStates m_playGameState;

    int m_Player1ScoreCount;
    int m_Player2ScoreCount;

    const char *m_leftScoreText;
    const char *m_rightScoreText;

    const int SCORE_THRESHOLD = 10;

public:
    GameInfo();
    GameStates PlayGameState();
    void StartGame();
    void SetScore(Ball *ball);
    void RestartGame();
    void StopGame();
};
