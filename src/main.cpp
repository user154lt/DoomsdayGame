#include "M5Cardputer.h"
#include "mainApplication.h"
#include "file/sdManager.h"

SDManager sdManager;

/* 
  MainApplication class controls application flow, declare as pointer so we can pass sd mount
  status to constructor. M5.begin must be called before we mount sd.
*/
MainApplication* application;


void init();
bool initSD();

// Call init function, instantiate application and draw screen.
void setup() {
  init();
  application = new MainApplication(M5Cardputer.Display, initSD());
  application->showCurrentScreen();
}

/*
  We only need to check the whether a single button has been pressed so notify application
  that key has been pressed by calling processInput
*/
void loop() {
  M5Cardputer.update();
  if(M5Cardputer.Keyboard.isChange()){
    if(M5Cardputer.Keyboard.isPressed()){
     application->processInput();
    }
  }
}

// Call M5 begin function and set brightness.
void init(){
  auto config = M5.config();
  M5Cardputer.begin(config);
  M5Cardputer.Display.setBrightness(54);
}

// Mount SD card if possible
bool initSD(){
  return sdManager.mount();   
}