#include "Paddle.h"

Paddle::Paddle(float xPosition, float yPosition)
{
    width = 10;
    height = 100;
    color = BLACK;
    speed = 550;

    x = xPosition;
    y = yPosition - height/2;
}
   

Rectangle Paddle::GetRect()
{
    return  Rectangle{
            x, 
            y, 
            width,
            height
        };
   
}
void Paddle::Draw()
{
    DrawRectangleRec(GetRect(),color);
   
}

void Paddle::Controls(KeyboardKey up, KeyboardKey down)
{
    if(IsKeyDown(up))
    {
        Update(-1.0);
        return;
    }

    if(IsKeyDown(down))
    {
        Update(1.0);
    }
}
void Paddle::Update(float yDir)
{
    y += speed * yDir * GetFrameTime();

    if(y + height > GetScreenHeight())
    {
        y = GetScreenHeight() - height;
        return;
    }

    if(y <= 0)
    {
        y = 0;
    }
   
    
}
