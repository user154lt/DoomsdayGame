#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "applicationScreen.h"
#include "gfx/menuGfx.h"
#include "menu/menu.h"

/*
    Class for managing menu screens. Manipulates menu state and draws screen
*/
class MenuScreen : public ApplicationScreen {

    private:

        MenuGfx gfx;
        Menu* menu;

    public:

        MenuScreen(LovyanGFX &mainGfx, Menu* firstMenu);
        void setCurrentMenu(Menu* currentMenu);
        void draw();
        void processInput();

};

#endif