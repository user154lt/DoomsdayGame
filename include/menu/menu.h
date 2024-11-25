#ifndef MENU_H
#define MENU_H

#include <vector>
#include "menu/menuItem.h"

/*
    Class to be used for menus, is instantiated with a title and list of MenuItems.
    Manages state of selection and provides functions for manipulating it.
*/
class Menu{

    private:

        std::string title;
        std::vector<MenuItem> items;
        int selectedIndex;

    public:

        Menu(std::string menuTitle, std::vector<MenuItem> menuItems);
        inline MenuItem operator[](int i){ return items[i]; };
        std::string getTitle();
        void setTitle(std::string newTitle);
        int getSize();
        int getSelectedIndex();

        // moveUp and moveDown functions wrap round if called when selectedIndex is at bounds
        void moveUp();
        void moveDown();
        void executeAction();
        
};

#endif