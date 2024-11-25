#ifndef MENU_ITEM_H
#define MENU_ITEM_H
 
#include <string> 
#include <functional>

/*
    Data class to hold each item of the menu, consists of the label and a function that will
    be called when the item is selected.
*/
typedef struct MenuItem{

    std::string label = "";
    std::function<void ()> action = []{};

    MenuItem(std::string itemLabel, std::function<void ()> itemAction) :
    label(itemLabel), action(itemAction){}

    void operator()(){action();};

} MenuItem;


#endif