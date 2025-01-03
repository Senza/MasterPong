#pragma once
#include <raylib.h>

class Paddle
{
    private:
        float x;
        float y;
        float speed;
        float width;
        float height;
        Color color;

        void Update(float yDir);

        
    public:
        Paddle(float xPosition, float yPosition);
        Rectangle GetRect();
        void Controls(KeyboardKey up, KeyboardKey down);
        void Draw();
       

};

