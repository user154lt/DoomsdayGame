#ifndef BORDER_H
#define BORDER_H

#include "M5GFX.h"

/*
    Graphics class for drawing gradient border round the screen, takes a reference to a sprite
    and draws the border round the edge
*/
class BorderGfx{
    private:
        LGFX_Sprite &sprite;
        void drawBorderRect(int margin);
    public:
        BorderGfx(LGFX_Sprite &mainSprite);
        void draw();
};

#endif