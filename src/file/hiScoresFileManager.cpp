#include "file/hiScoresFileManager.h"
#include <SD.h>

HiScoresFileManager::HiScoresFileManager() :
    hiScoresJson()
{

}

HiScores HiScoresFileManager::getHiScores(){
    HiScores result = readFile(SD);
    return result; 
}

// If file exists and can be opened use ArduinoJson wrapper to deserialize contents, else return defaults
HiScores HiScoresFileManager::readFile(fs::FS &fs){
    HiScores result;
    if(fs.exists(FILE_PATH)){
        File file = fs.open(FILE_PATH);
        if(file){
            std::string json;
            if(file.available()){
                json = file.readString().c_str();
            }
            result = hiScoresJson.scoresFrom(json);
        }
    }
    return result;
}



void HiScoresFileManager::saveHiScores(HiScores hiScores){
    saveFile(SD, hiScores);
}

// Create dir then if file can be opened serialize scores using ArduinoJson wrapper and save to file
void HiScoresFileManager::saveFile(fs::FS &fs, HiScores hiScores){
    createDir(fs);
    File file = fs.open(FILE_PATH, FILE_WRITE);
    if(file){
        std::string json = hiScoresJson.jsonFrom(hiScores);
        file.print(json.c_str());
    }
}


void HiScoresFileManager::createDir(fs::FS &fs){
    if(!fs.exists(DIR_PATH)){
        fs.mkdir(DIR_PATH);
    }
}