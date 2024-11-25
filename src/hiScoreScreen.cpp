#include "hiScoreScreen.h"
#include "M5Cardputer.h"

HiScoreScreen::HiScoreScreen(LovyanGFX &gfx, HiScoreCoordinator &scoreCoordinator, std::function<void ()> showMainMenu) :
    scoreCoordinator(scoreCoordinator),
    hiScoresGfx(gfx),
    showMainMenu(showMainMenu),
    selectedIndex(0)
{

}

void HiScoreScreen::loadScores(){
    hiScores = scoreCoordinator.getHiScores();
}

void HiScoreScreen::draw(){
    hiScoresGfx.drawScreen(hiScores, selectedIndex);
}

void HiScoreScreen::processInput(){
    if(M5Cardputer.Keyboard.isKeyPressed('`')){
        showMainMenu();    
    } else if(
        M5Cardputer.Keyboard.isKeyPressed('/') || M5Cardputer.Keyboard.isKeyPressed(',')
                || M5Cardputer.Keyboard.isKeyPressed('.') || M5Cardputer.Keyboard.isKeyPressed(';')
            ){
                changeSelected();
                draw();
    } else if(M5Cardputer.Keyboard.keysState().enter){
        onEnterPressed();
    }
}

void HiScoreScreen::changeSelected(){
    selectedIndex ^= 1;
}

void HiScoreScreen::onEnterPressed(){
    if(selectedIndex == 0){
        showMainMenu();
    } else {
        scoreCoordinator.resetScores();
        loadScores();
        draw();
    }
}