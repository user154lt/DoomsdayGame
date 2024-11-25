#include "gameScreen.h"
#include "M5Cardputer.h"

GameScreen::GameScreen(LovyanGFX &mainGfx, HiScoreCoordinator &scoreCoordinator, GameScreenCbs callbacks) : 
    scoreCoordinator(scoreCoordinator),
    showMainMenu(callbacks.showMainMenu),
    showGameOverMenu(callbacks.showGameOverMenu),
    dateUtils(),
    gfx(mainGfx, dateUtils), 
    doomsday(dateUtils),
    selectedDay(0)
{

}

void GameScreen::setupGame(){
    targetDate = dateUtils.randomDate();
    correctDay = doomsday.dayOfWeekFor(targetDate);
    selectedDay = 0;
    startTime = millis();
}

void GameScreen::draw(){
    gfx.drawGameScreen(selectedDay, targetDate);
}

void GameScreen::processInput(){
    if(M5Cardputer.Keyboard.isKeyPressed('`')){
        showMainMenu();
    } else if(M5Cardputer.Keyboard.isKeyPressed('/')){
        selectNextDay();
        draw();
    } else if(M5Cardputer.Keyboard.isKeyPressed(',')){
        selectPreviousDay();
        draw();
    } else if(M5Cardputer.Keyboard.isKeyPressed('.')){
        selectOppositeRow();
        draw();
    } else if(M5Cardputer.Keyboard.isKeyPressed(';')){
        selectOppositeRow();
        draw();
    } else if(M5Cardputer.Keyboard.keysState().enter){
        handleGuess();
    }
}

void GameScreen::selectNextDay(){
    selectedDay = (selectedDay + 1 <= 6) ? selectedDay + 1 : 0;
}

void GameScreen::selectPreviousDay(){
    selectedDay = (selectedDay - 1 >= 0) ? selectedDay  - 1 : 6; 
}

void GameScreen::selectOppositeRow(){
    if(selectedDay != 3){
        selectedDay = (selectedDay < 3) ? selectedDay + 4 : selectedDay - 4;
    } else {
        selectedDay = 6;
    }
}

void GameScreen::handleGuess(){
    std::string message;
    if(selectedDay == correctDay){
        int time = timeTaken();
        int hiScorePosition =  checkHiScore(time);
        message = correctMessage(time, hiScorePosition);
    } else {
        message = incorrectMessage();
    }
    showGameOverMenu(message);
}


int GameScreen::timeTaken(){
    float seconds = (millis() - startTime) / 1000.0f;
    int result = static_cast<int>(seconds);
    return result;
}

int GameScreen::checkHiScore(int time){
    Score score;
    score.day = targetDate.day;
    score.month = targetDate.month;
    score.year = targetDate.year;
    score.secs = time;
    int result = scoreCoordinator.saveIfHiScore(score);
    return result;
}

std::string GameScreen::correctMessage(int time, int scorePosition){
    char buffer[50];
    if(scorePosition != -1){
        sprintf(buffer, "HiScore! %03d secs", time);
    } else {
        sprintf(buffer, "Correct in %03d secs", time);
    }
    return buffer;
}

std::string GameScreen::incorrectMessage(){
    char buffer[30];
    sprintf(buffer, "Incorrect! Day = %s", dateUtils.nameFor(correctDay).c_str());
    return buffer;
}
