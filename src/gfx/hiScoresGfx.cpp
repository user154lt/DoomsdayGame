#include "gfx/hiScoresGfx.h"
#include "gfx/font/UbuntuMono_Bold9pt7b.h"
#include "gfx/materialColors.h"

HiScoresGfx::HiScoresGfx(LovyanGFX &gfx) :
    gfx(gfx),
    sprite(&gfx),
    border(sprite)
{

}

void HiScoresGfx::drawScreen(HiScores &hiScores, int selectedIndex){
    sprite.createSprite(gfx.width(), gfx.height());
    draw(hiScores, selectedIndex);
    sprite.pushSprite(0, 0);
    sprite.deleteSprite();
}

void HiScoresGfx::draw(HiScores &hiScores, int selectedIndex){
    border.draw();
    drawHiScores(hiScores);
    drawButtons(selectedIndex);
}

void HiScoresGfx::drawHiScores(HiScores &hiScores){
    setTextFormat();
    for(int i = 0; i < 5; i++){
        drawScore(hiScores[i], i);
    }
}

void HiScoresGfx::setTextFormat(){
    sprite.setFont(&UbuntuMono_Bold9pt7b);
    sprite.setTextColor(PURPLE_A400);
}

void HiScoresGfx::drawScore(Score score, int position){
    int x = gfx.width() / 2;
    int y = 10 + (position * 18);
    char buffer[20];
    sprintf(buffer, "%1d: %02d/%02d/%4d %03d", (position + 1), score.day, score.month, score.year, score.secs);
    sprite.drawCenterString(buffer, x, y);
}

void HiScoresGfx::drawButtons(int selectedIndex){
    for(int i = 0; i < 2; i++){
        ButtonProperties properties  = makeButtonProperties(i);
        std::string label = (i == 0) ? "Main menu" : "Reset scores";
        ButtonGfx buttonGfx = ButtonGfx(properties, label, sprite);
        buttonGfx.draw(i == selectedIndex);
    }
}

ButtonProperties HiScoresGfx::makeButtonProperties(int index){
    ButtonDimensions dimensions = makeButtonDimensions();
    ButtonPosition position = makeButtonPosition(dimensions, index);
    ButtonColors colors;
    return {dimensions, position, colors};
}

ButtonDimensions HiScoresGfx::makeButtonDimensions(){
    ButtonDimensions dimensions;
    dimensions.h = 20;
    dimensions.w = 75;
    return dimensions;
}

ButtonPosition HiScoresGfx::makeButtonPosition(ButtonDimensions dimensions, int index){
    ButtonPosition position;
    position.x = ((index + 1) * 30) + (index * dimensions.w);
    position.y = 105;
    return position;
}


