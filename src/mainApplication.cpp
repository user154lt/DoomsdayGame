#include "mainApplication.h"

MainApplication::MainApplication(LovyanGFX &mainGfx, bool isSDMounted) : 
    mainMenu("Doomsday game!",{
            MenuItem("Play", [this]{ startGame(); }),
            MenuItem("Hi Scores", [this]{ showHiScores(); }),
            MenuItem("More info", [this]{ showInfoScreen(); })
    }),
    gameOverMenu("", {
        MenuItem("New game", [this]{ startGame(); }),
        MenuItem("Main menu", [this]{ showMainMenu(); })
    }), 
    scoreCoordinator(isSDMounted),
    menuScreen(mainGfx, &this->mainMenu),
    gameScreen(
        mainGfx, scoreCoordinator, {[this]{ showMainMenu(); }, [this](std::string message){ showGameOverMenu(message);} }
    ),
    hiScoreScreen(mainGfx, scoreCoordinator, [this] { showMainMenu(); }),
    moreInfoScreen(mainGfx, [this] { showMainMenu(); }),
    appScreen(&menuScreen)
{

}

void MainApplication::showCurrentScreen(){
    appScreen->draw();
}

void MainApplication::processInput(){
    appScreen->processInput();
}

void MainApplication::startGame(){
    gameScreen.setupGame();
    appScreen = &gameScreen;
    showCurrentScreen();
}

void MainApplication::showMainMenu(){
    menuScreen.setCurrentMenu(&mainMenu);
    appScreen = &menuScreen;
    showCurrentScreen();
}

void MainApplication::showGameOverMenu(std::string message){
    gameOverMenu.setTitle(message);
    menuScreen.setCurrentMenu(&gameOverMenu);
    appScreen = &menuScreen;
    showCurrentScreen();
}

void MainApplication::showHiScores(){
    hiScoreScreen.loadScores();
    appScreen = &hiScoreScreen;
    showCurrentScreen();
}

void MainApplication::showInfoScreen(){
    appScreen = &moreInfoScreen;
    showCurrentScreen();
}