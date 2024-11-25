#include "menu/menu.h"

Menu::Menu(std::string menuTitle, std::vector<MenuItem> menuItems) : 
    title(menuTitle),
    items(menuItems),
    selectedIndex(0){

}

std::string Menu::getTitle(){
    return title;
}

void Menu::setTitle(std::string newTitle){
    title = newTitle;
}

int Menu::getSize(){
    return items.size();
}

int Menu::getSelectedIndex(){
    return selectedIndex;
}

void Menu::moveUp(){
    selectedIndex = (selectedIndex - 1 >= 0) ? selectedIndex - 1 : items.size() - 1;
}

void Menu::moveDown(){
    selectedIndex = (selectedIndex + 1 < items.size()) ? selectedIndex + 1 : 0; 
}

void Menu::executeAction(){
    items[selectedIndex]();
}