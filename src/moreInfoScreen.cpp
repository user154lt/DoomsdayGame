#include "moreInfoScreen.h"

MoreInfoScreen::MoreInfoScreen(LovyanGFX &gfx, std::function<void ()> showMainMenu) : 
    infoGfx(MoreInfoGfx(gfx)),
    showMainMenu(showMainMenu){

    }

void MoreInfoScreen::draw(){
    infoGfx.drawScreen();
}

void MoreInfoScreen::processInput(){
    showMainMenu();
}