#ifndef MORE_INFO_GFX_H
#define MORE_INFO_GFX_H

#include "M5GFX.h"
#include "gfx/borderGfx.h"

/*
    Class for drawing screen displaying QR linking to Doomsday rule wikipedia page
*/
class MoreInfoGfx{
    private:
        LovyanGFX &gfx;
        LGFX_Sprite sprite;
        BorderGfx border;
        const char* QR_URL = "https://en.wikipedia.org/wiki/Doomsday_rule";

        void draw();
        void drawTitle(); 
        void setTextFormat();
        void drawQRCode();       
        void drawReturnMessage();

    public:
        MoreInfoGfx(LovyanGFX &mainGfx);
        void drawScreen();
        
};

#endif