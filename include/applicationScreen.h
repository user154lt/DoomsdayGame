#ifndef APPLICATION_SCREEN_H
#define APPLICATION_SCREEN_H

/*
    Abstract class that screen classes inherit from, provides functions for drawing 
    screen and responding to input
*/
class ApplicationScreen{

    public:
        virtual void draw();
        virtual void processInput();

};

#endif