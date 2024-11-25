#ifndef HI_SCORES_GFX_H
#define HI_SCORES_GFX_H

#include "M5GFX.h"
#include "gfx/borderGfx.h"
#include "gfx/buttonGfx.h"
#include "file/hiScores.h"

/*
    Graphics class for drawing high scores screen, takes a reference to M5 display
*/
class HiScoresGfx{

    private:

        LovyanGFX &gfx;
        LGFX_Sprite sprite;
        BorderGfx border;

        void draw(HiScores &HiScores, int selectedIndex);
        void drawHiScores(HiScores &hiScores);
        void setTextFormat();
        void drawScore(Score score, int position);
        void drawButtons(int selectedIndex);
        ButtonProperties makeButtonProperties(int index);
        ButtonDimensions makeButtonDimensions();
        ButtonPosition makeButtonPosition(ButtonDimensions dimensions, int index);

    public:

        HiScoresGfx(LovyanGFX &gfx);
        void drawScreen(HiScores &hiScores, int selectedIndex);

};

#endif