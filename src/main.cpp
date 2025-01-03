#include <iostream>
#include "ball.h"
#include "Paddle.h"
#include "GameInfo.h"
#include <raylib.h>

#define GAMEGREEN \
    CLITERAL(Color) { 124, 252, 0, 255 }

void InitializeGame(GameInfo *gameInfo, Ball *ball);
void BeginGame(GameInfo *gameInfo, Ball *ball, Paddle *player1, Paddle *player2);

int main()
{
    GameInfo gameInfo;

    const int screenWidth = 1280;
    const int screenHeight = 800;

    Ball ball(screenWidth / 2, screenHeight / 2);
    Paddle player1(20, screenHeight / 2);
    Paddle player2(screenWidth - 30, screenHeight / 2);
    InitWindow(screenWidth, screenHeight, "Pong Master");
    SetTargetFPS(FLAG_VSYNC_HINT);

    while (!WindowShouldClose())
    {
        InitializeGame(&gameInfo, &ball);
        BeginGame(&gameInfo, &ball, &player1, &player2);
    }
    CloseWindow();

    return 0;
}

void InitializeGame(GameInfo *gameInfo, Ball *ball)
{
    gameInfo->StartGame();
    gameInfo->SetScore(ball);
    gameInfo->StopGame();
}

void BeginGame(GameInfo *gameInfo, Ball *ball, Paddle *player1, Paddle *player2)
{

    if (gameInfo->PlayGameState() == INSESSION)
    {
        player1->Controls(KEY_W, KEY_S);
        player2->Controls(KEY_UP, KEY_DOWN);

        ball->Update();
        ball->IsCollidingWithPaddle(player1, -1);
        ball->IsCollidingWithPaddle(player2, 1);

        DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 200, SKYBLUE);
        DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 150, BLUE);

        DrawLineEx(Vector2{GetScreenWidth() / 2.0, GetScreenHeight() / 3.5}, Vector2{GetScreenWidth() / 2.0, 0}, 20, SKYBLUE);
        DrawLineEx(Vector2{GetScreenWidth() / 2.0, GetScreenHeight()}, Vector2{GetScreenWidth() / 2.0, GetScreenHeight() - (GetScreenHeight() / 3.5)}, 20, SKYBLUE);
    }

    BeginDrawing();
    ClearBackground(BLUE);

    player1->Draw();
    player2->Draw();
    ball->Draw();

    EndDrawing();
}
