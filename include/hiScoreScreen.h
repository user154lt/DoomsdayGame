#ifndef HI_SCORES_SCREEM_H
#define HI_SCORES_SCREEN_H

#include "applicationScreen.h"
#include "hiScoreCoordinator.h"
#include "gfx/hiScoresGfx.h"
#include <functional>

/*
    Manages high score screen. Gets high scores and draws screen
*/
class HiScoreScreen : public ApplicationScreen{

    private:

        HiScoreCoordinator &scoreCoordinator;
        HiScoresGfx hiScoresGfx;
        std::function<void ()> showMainMenu;
        HiScores hiScores;
        int selectedIndex;

        void changeSelected();
        void onEnterPressed();

    public:

        HiScoreScreen(LovyanGFX &gfx, HiScoreCoordinator &scoreCoordinator, std::function<void ()> showMainMenu);
        void loadScores();
        void draw();
        void processInput();

};

#endif