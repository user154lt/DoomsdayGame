#include "gfx/buttonGfx.h"
#include "gfx/font/UbuntuMono_Regular6pt7b.h"

ButtonGfx::ButtonGfx(ButtonProperties properties, std::string labelString, LGFX_Sprite &mainSprite) :
    dimensions(properties.dimensions),
    position(properties.position),
    colors(properties.colors),
    label(labelString),
    sprite(mainSprite){

}

void ButtonGfx::draw(bool isSelected){
    drawButton(isSelected);
    drawLabel(isSelected);
}

void ButtonGfx::drawButton(bool isSelected){
    int color = (isSelected) ? colors.selected : colors.unselected;
    sprite.fillRoundRect(position.x, position.y, dimensions.w, dimensions.h, 3, color);
}

void ButtonGfx::drawLabel(bool isSelected){
    setTextFormat(isSelected);
    int labelX = position.x + (dimensions.w / 2);
    int labelY = position.y + (dimensions.h / 4);
    sprite.drawCenterString(label.c_str(), labelX, labelY);
}

void ButtonGfx::setTextFormat(bool isSelected){
    int color = (isSelected) ? colors.fontSelected : colors.fontUnselected;
    int bgColor = (isSelected) ? colors.selected : colors.unselected;
    sprite.setFont(&UbuntuMono_Regular6pt7b);
    sprite.setTextColor(color, bgColor);
}