#ifndef MENU_GFX_H
#define MENU_GFX_H

#include "M5GFX.h"
#include <string>
#include "menu/menu.h"
#include "gfx/buttonGfx.h"
#include "gfx/borderGfx.h"

/*
    Class for drawing menu screens, takes a reference to M5 display
*/
class MenuGfx{

    private:

        LovyanGFX &gfx;
        LGFX_Sprite sprite;
        BorderGfx border;

        ButtonProperties makeButton(int menuPosition);
        ButtonDimensions makeButtonDimensions();
        ButtonPosition makeButtonPosition(ButtonDimensions dimensions, int menuPosition);
      
    public:
    
        MenuGfx(LovyanGFX &mainGfx);
        void draw(Menu* menu);
        void drawMenuBorder();
        void drawMenuTitle(std::string title);
        void drawMenuItem(std::string label, int menuPosition, bool isSelected);

};

#endif