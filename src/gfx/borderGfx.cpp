#include "gfx/borderGfx.h"
#include "gfx/materialColors.h"

BorderGfx::BorderGfx(LGFX_Sprite &mainSprite) :
sprite(mainSprite){

}

void BorderGfx::draw(){
    drawBorderRect(2);
    drawBorderRect(4);
}

void BorderGfx::drawBorderRect(int margin){
    sprite.drawGradientHLine(margin, margin, sprite.width() - (margin * 2), BLUE_500, RED_500);
    sprite.drawGradientVLine(sprite.width() - margin, margin, sprite.height() - (margin * 2), RED_500, GREEN_500);
    sprite.drawGradientHLine(margin, sprite.height() - margin, sprite.width() - (margin * 2), ORANGE_500, GREEN_500);
    sprite.drawGradientVLine(margin, margin, sprite.height() - (margin * 2), BLUE_500, ORANGE_500);
}