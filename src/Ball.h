#pragma once
#include "Paddle.h"
#include <raylib.h>


class Ball
{
    private:
        float x;
        float y;
        float speedX;
        float speedY;
        float radius;
        Color color;

        float Direction();
           
    public:
        Ball(float xPosition, float yPosition);
        Vector2 GetPosition();
        void Draw();
        void Update();
        void IsCollidingWithPaddle(Paddle* player, int dir);
        void Restart();
};
