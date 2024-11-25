#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "applicationScreen.h"
#include "hiScoreCoordinator.h"
#include <functional>
#include "gfx/gameGfx.h"
#include "date/doomsdayCalculator.h"

// Data class to hold callbacks used by the game screen
typedef struct GameScreenCbs{
    std::function<void ()> showMainMenu;
    std::function<void (std::string message)> showGameOverMenu;
} GameScreenCbs;


/*
    Game screen class used for main game. Handles game state and draws the screen
*/
class GameScreen : public ApplicationScreen{

    private:

        HiScoreCoordinator &scoreCoordinator;
        std::function<void ()> showMainMenu;
        std::function<void (std::string message)> showGameOverMenu;
        DateUtils dateUtils;
        GameGfx gfx;
        DoomsdayCalculator doomsday;

        Date targetDate;
        int correctDay;
        int selectedDay;
        int startTime;


        void selectNextDay();
        void selectPreviousDay();
        void selectOppositeRow();
        void handleGuess();
        std::string correctMessage(int time, int scorePosition);
        std::string incorrectMessage();
        int timeTaken();
        int checkHiScore(int time);

    public:
        GameScreen(LovyanGFX &mainGfx, HiScoreCoordinator &scoreCoordinator, GameScreenCbs callbacks);
        void setupGame();
        void draw();
        void processInput();
};

#endif