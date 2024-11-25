#ifndef MORE_INFO_SCREEN_H
#define MORE_INFO_SCREEN_H

#include "applicationScreen.h"
#include "gfx/moreInfoGfx.h"
#include <functional>

/*
    Simple screen that displays a QR code linking to the Doomsday rule wikipedia
    page. Is not interactive in any way
*/
class MoreInfoScreen : public ApplicationScreen{

    private:

        MoreInfoGfx infoGfx;
        std::function<void ()> showMainMenu;

    public:

        MoreInfoScreen(LovyanGFX &gfx, std::function<void ()> showMainMenu);
        void draw();
        void processInput();

};

#endif