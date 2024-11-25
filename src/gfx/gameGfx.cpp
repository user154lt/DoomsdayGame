#include "gfx/gameGfx.h"
#include <string>
#include "gfx/materialColors.h"
#include "gfx/font/UbuntuMono_Bold10pt7b.h"

GameGfx::GameGfx(LovyanGFX &mainGfx, DateUtils &dateUtils) : 
    gfx(mainGfx),
    sprite(&mainGfx),
    border(BorderGfx(sprite)),
    dateUtils(dateUtils)
{

}

void GameGfx::drawGameScreen(int selectedOption, Date date){
    sprite.createSprite(gfx.width(), gfx.height());
    border.draw();
    drawText(date);
    for (int i = 0; i < 7; i++){
        ButtonProperties properties = makeButtonProperties(i);
        std::string label = dateUtils.nameFor(i);
        ButtonGfx buttonGfx = ButtonGfx(properties, label, sprite);
        buttonGfx.draw(selectedOption == i);
    }
    sprite.pushSprite(0,0);
    sprite.deleteSprite();
}

void GameGfx::drawText(Date date){
    setTextFormat();
    drawMessage();
    drawDate(date);
}

void GameGfx::setTextFormat(){
    sprite.setFont(&UbuntuMono_Bold10pt7b);
    sprite.setTextColor(PURPLE_A400);
}

void GameGfx::drawMessage(){
    sprite.drawCenterString("What's the day:", gfx.width() / 2, 10);
}

void GameGfx::drawDate(Date date){
    char message[12];
    sprintf(message, "%02d/%02d/%4d?", date.day, date.month, date.year);
    sprite.drawCenterString(message, gfx.width() / 2, 32);
}

ButtonProperties GameGfx::makeButtonProperties(int dayNumber){
    ButtonDimensions dimensions = makeButtonDimensions();
    ButtonPosition position = makeButtonPosition(dimensions, dayNumber);
    ButtonColors colors;
    return {dimensions, position, colors};
}

ButtonDimensions GameGfx::makeButtonDimensions(){
    ButtonDimensions dimensions;
    dimensions.w = 40;
    dimensions.h = 20;
    return dimensions;
}

ButtonPosition GameGfx::makeButtonPosition(ButtonDimensions dimensions, int dayNumber){
    ButtonPosition position;
    if (dayNumber < 4){
        position.x = ((dayNumber + 1) * 16) + (dayNumber * dimensions.w);
        position.y = 65;
    } else{
        int delta = dayNumber - 4;
        position.x = ((delta + 1) * 30) + (delta * dimensions.w);
        position.y = 95;
    }
    return position;
}
