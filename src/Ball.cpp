#include "random"
#include "iostream"
#include "ball.h"

Ball::Ball(float xPositon, float yPositon)
{
    speedX = 300.0 * Direction();
    speedY = 300.0 * Direction();
    radius = 10.0;
    color = RAYWHITE;

    x = xPositon;
    y = yPositon;
}

Vector2 Ball::GetPosition()
{
    return Vector2{x, y};
}
void Ball::Draw()
{
    DrawCircle(x, y, radius, color);
}

void Ball::Update()
{
    x += speedX * GetFrameTime();
    y += speedY * GetFrameTime();

    if (y <= 0)
    {
        y = 0;
        speedY *= -1;
    }

    if (y >= GetScreenHeight())
    {
        y = GetScreenHeight();
        speedY *= -1;
    }
}

void Ball::IsCollidingWithPaddle(Paddle *player, int dir)
{
    if (CheckCollisionCircleRec(GetPosition(), radius, player->GetRect()))
    {
        speedX *= -1.1f;

        float yVelocity = (player->GetRect().y + player->GetRect().height / 2) - y;
        speedY += (yVelocity * yVelocity) / yVelocity;
        speedY *= 1.01f;
    }
}

void Ball::Restart()
{
    speedX = 300.0 * Direction();
    speedY = 300.0 * Direction();

    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
}

float Ball::Direction()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 2);

    return (dis(gen) == 1) ? 1 : -1;
}