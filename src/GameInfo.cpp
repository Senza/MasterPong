#include "GameInfo.h"
#include "raylib.h"

GameInfo::GameInfo()
{
    m_Player2ScoreCount = 0;
    m_Player1ScoreCount = 0;

    m_playGameState = START;
}
void GameInfo::StartGame()
{
    if (IsKeyPressed(KEY_ENTER) && m_playGameState == START)
    {
        m_playGameState = INSESSION;
    }

    if (m_playGameState == START)
    {
        const char *textTitle = "Pong Master";
        int textTitleSize = MeasureText(textTitle, 50);
        DrawText(textTitle, GetScreenWidth() / 2 - textTitleSize / 2, GetScreenHeight() / 2, 50, GREEN);

        const char *text = "[Start] Press enter";
        int textSize = MeasureText(text, 20);
        DrawText(text, GetScreenWidth() / 2 - textSize / 2, GetScreenHeight() / 2 + 75, 20, WHITE);
    }
}

void GameInfo::SetScore(Ball *ball)
{
    if (m_playGameState != INSESSION)
    {
        return;
    }
    if (ball->GetPosition().x < 0)
    {
        ball->Restart();
        m_Player2ScoreCount += 1;
        if (m_Player2ScoreCount == SCORE_THRESHOLD)
        {
            m_playGameState = ENDED;
            return;
        }

        
    }
    else if (ball->GetPosition().x > GetScreenWidth())
    {
         ball->Restart();
        m_Player1ScoreCount += 1;
        if (m_Player1ScoreCount == SCORE_THRESHOLD)
        {
            m_playGameState = ENDED;
            return;
        }
       
    }

    m_leftScoreText = TextFormat("Score:\n%d", m_Player1ScoreCount);
    m_rightScoreText = TextFormat("Score:\n%d", m_Player2ScoreCount);

    DrawText(m_leftScoreText, 10, 10, 20, YELLOW);
    int right_pos = GetScreenWidth() - MeasureText(m_rightScoreText, 20);
    DrawText(m_rightScoreText, right_pos - 10, 10, 20, YELLOW);
}

GameStates GameInfo::PlayGameState()
{
    return m_playGameState;
}

void GameInfo::RestartGame()
{
    m_Player1ScoreCount = 0;
    m_Player2ScoreCount = 0;
    m_playGameState = INSESSION;
}
void GameInfo::StopGame()
{
    if (m_playGameState == ENDED)
    {
        m_playGameState = ENDED;
        const char *text = nullptr;

        if (m_Player1ScoreCount)
        {
            text = TextFormat("Player 1 won");
        }
        else
        {
            text = TextFormat("Player 2 won");
        }

        int textWidth = MeasureText(text, 40);
        DrawText(m_rightScoreText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2, 40, YELLOW);

        text = "[Restart] Press enter";
        int textSize = MeasureText(text, 20);
        DrawText(text, GetScreenWidth() / 2 - textSize / 2, GetScreenHeight() / 2 + 75, 20, WHITE);

        if(IsKeyPressed(KEY_ENTER))
            RestartGame();
    }
}