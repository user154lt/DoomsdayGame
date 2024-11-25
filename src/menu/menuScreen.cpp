#include "menu/menuScreen.h"
#include "M5Cardputer.h"

MenuScreen::MenuScreen(LovyanGFX &mainGfx, Menu *firstMenu):
    gfx(mainGfx),
    menu(firstMenu)
{  

}

void MenuScreen::setCurrentMenu(Menu *currentMenu){
    menu = currentMenu;
}

void MenuScreen::draw(){
    gfx.draw(menu);
}

void MenuScreen::processInput(){
    if(M5Cardputer.Keyboard.isKeyPressed(';')){
        menu->moveUp();
        draw();
    } else if(M5Cardputer.Keyboard.isKeyPressed('.')){
        menu->moveDown();
        draw();
    } else if(M5Cardputer.Keyboard.keysState().enter){
        menu->executeAction();
    }
}