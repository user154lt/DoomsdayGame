#include "gfx/menuGfx.h"
#include "gfx/materialColors.h"
#include "gfx/font/UbuntuMono_Bold10pt7b.h"

MenuGfx::MenuGfx(LovyanGFX &mainGfx) : 
    gfx(mainGfx),
    sprite(&gfx),
    border(BorderGfx(sprite))
{

}

void MenuGfx::draw(Menu* menu){
    sprite.createSprite(gfx.width(), gfx.height());
    drawMenuBorder();
    drawMenuTitle(menu->getTitle());
    int selectedIndex = menu->getSelectedIndex();
    for(int i = 0; i < menu->getSize(); i++){
        drawMenuItem((*menu)[i].label, i, i == selectedIndex);
    } 
    sprite.pushSprite(0,0);
    sprite.deleteSprite();
}

void MenuGfx::drawMenuBorder(){
    border.draw();
}

void MenuGfx::drawMenuTitle(std::string title){
    sprite.setFont(&UbuntuMono_Bold10pt7b);
    sprite.setTextColor(PURPLE_A400, BLACK);
    sprite.drawCenterString(title.c_str(), gfx.width() / 2, 15);
}

void MenuGfx::drawMenuItem(std::string label, int menuPosition, bool isSelected){
    ButtonProperties properties = makeButton(menuPosition);
    ButtonGfx buttonGfx = ButtonGfx(properties, label, sprite);
    buttonGfx.draw(isSelected);
}


ButtonProperties MenuGfx::makeButton(int menuPosition){
    ButtonDimensions dimensions = makeButtonDimensions();
    ButtonPosition position = makeButtonPosition(dimensions, menuPosition);
    ButtonColors colors;
    return {dimensions, position, colors};
}

ButtonDimensions MenuGfx::makeButtonDimensions(){
    ButtonDimensions dimensions;
    dimensions.w = 80;
    dimensions.h = 20;
    return dimensions;
}

ButtonPosition MenuGfx::makeButtonPosition(ButtonDimensions dimensions, int menuPosition){
    ButtonPosition position;
    position.x = (gfx.width() - dimensions.w) / 2; 
    position.y = (dimensions.h + 10) * menuPosition + 40;
    return position;
}
