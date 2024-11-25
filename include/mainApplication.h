#ifndef MAIN_APPLICATION_H
#define MAIN_APPLICATION_H

#include "menu/menu.h"
#include "hiScoreCoordinator.h"
#include "menu/menuScreen.h"
#include "gameScreen.h"
#include "hiScoreScreen.h"
#include "moreInfoScreen.h"
#include "applicationScreen.h"

/*
    Main class for controlling the application
*/
class MainApplication{

    private:

        Menu mainMenu;
        Menu gameOverMenu;
        HiScoreCoordinator scoreCoordinator;

        // Classes to manage various screens of the app, all are dervied from ApplicationScreen
        MenuScreen menuScreen;
        GameScreen gameScreen;
        HiScoreScreen hiScoreScreen;
        MoreInfoScreen moreInfoScreen;

        // Pointer to current screen
        ApplicationScreen* appScreen;

        void startGame();
        void showMainMenu();
        void showGameOverMenu(std::string message);
        void showHiScores();
        void showInfoScreen();

    public:

        MainApplication(LovyanGFX &mainGfx, bool isSDMounted);
        void showCurrentScreen();
        void processInput();

};

#endif
