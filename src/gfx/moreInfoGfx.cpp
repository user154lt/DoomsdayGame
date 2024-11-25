#include "gfx/moreInfoGfx.h"
#include "gfx/font/UbuntuMono_Regular6pt7b.h"
#include "gfx/materialColors.h"

MoreInfoGfx::MoreInfoGfx(LovyanGFX &mainGfx) :
    gfx(mainGfx),
    sprite(&gfx),
    border(BorderGfx(sprite))
{

}

void MoreInfoGfx::drawScreen(){
    sprite.createSprite(gfx.width(), gfx.height());
    draw();
    sprite.pushSprite(0, 0);
    sprite.deleteSprite();
}

void MoreInfoGfx::draw(){
    border.draw();
    drawTitle();
    drawQRCode();
    drawReturnMessage();
}

void MoreInfoGfx::drawTitle(){
    setTextFormat();
    sprite.drawCenterString("Learn the doomsday rule:", gfx.width() / 2, 10);
}

void MoreInfoGfx::setTextFormat(){
    sprite.setFont(&UbuntuMono_Regular6pt7b);
    sprite.setTextColor(PURPLE_A400);
}

void MoreInfoGfx::drawQRCode(){
    sprite.qrcode(QR_URL, 80, 25, 80);
}

void MoreInfoGfx::drawReturnMessage(){
    sprite.drawCenterString("Press any key to return", gfx.width() / 2, 115);
}