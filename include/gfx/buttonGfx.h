#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include "gfx/materialColors.h"
#include "M5GFX.h"
#include <string>

typedef struct{
    int x, y;
} ButtonPosition;

typedef struct{
    int w, h;
} ButtonDimensions;

// Holds the colours for the button, uses default values if none specified
typedef struct ButtonColors{
    int unselected = LIGHT_BLUE_900;
    int selected = LIGHT_BLUE_400;
    int fontSelected = GREY_900;
    int fontUnselected = BLUE_GREY_900;
} ButtonColors;

/*
    Wraps round the structs for the button properties so that one object containing
    all the button properties can be passed to the constructor
*/
typedef struct ButtonProperties{
    ButtonDimensions dimensions;
    ButtonPosition position;
    ButtonColors colors;
} ButtonProperties;

/*
    Graphics class for drawing a single button on a sprite
*/
class ButtonGfx{
    private:
        ButtonDimensions dimensions;
        ButtonPosition position;
        ButtonColors colors;
        std::string label;
        LGFX_Sprite &sprite;

        void drawButton(bool isSelected);
        void drawLabel(bool isSelected);
        void setTextFormat(bool isSelected);

    public:
        ButtonGfx(ButtonProperties properties, std::string label, LGFX_Sprite &mainSprite);
        void draw(bool isSelected);
};

#endif