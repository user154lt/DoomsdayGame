#ifndef GAME_GFX_H
#define GAME_GFX_H

#include "M5GFX.h"
#include "date/dateUtils.h"
#include "gfx/borderGfx.h"
#include "gfx/buttonGfx.h"


/*
    Graphics class for drawing main game screen, takes a reference to M5 display.
*/
class GameGfx{
    private:

        LovyanGFX &gfx;
        DateUtils &dateUtils;
        LGFX_Sprite sprite;
        BorderGfx border;
        
        void drawText(Date date);
        void setTextFormat();
        void drawMessage();
        void drawDate(Date date);
        ButtonProperties makeButtonProperties(int dayNumber);
        ButtonDimensions makeButtonDimensions();
        ButtonPosition makeButtonPosition(ButtonDimensions dimensions, int dayNumber);

    public:

        GameGfx(LovyanGFX &mainGfx, DateUtils &dateUtils);
        void drawGameScreen(int selectedOption, Date date);

};

#endif