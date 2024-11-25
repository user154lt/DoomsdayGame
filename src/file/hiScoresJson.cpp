#include "file/hiScoresJson.h"
#include "ArduinoJson.h"

// Loop through scores and add each property to the json array. Serialize and return the resulting string.
std::string HiScoresJson::jsonFrom(HiScores hiScores){
    JsonDocument jsonDoc;
    JsonArray array = jsonDoc.to<JsonArray>();
    for(int i = 0; i < 5; i++){
        Score score = hiScores.scores[i];
        array.add(score.day);
        array.add(score.month);
        array.add(score.year);
        array.add(score.secs);
    }
    std::string result;
    serializeJson(jsonDoc, result);
    return result;
}

// Loop 5 times building a high scores object using the relevant offsets from the json array. Use default values on failure.
HiScores HiScoresJson::scoresFrom(std::string json){
    JsonDocument jsonDoc;
    deserializeJson(jsonDoc, json);
    JsonArray array = jsonDoc.as<JsonArray>();
    HiScores result;
    for(int i = 0; i < 5; i++){
        Score score;
        int index = i * 4;
        score.day = array[index] | 1;
        score.month = array[index + 1] | 1;
        score.year = array[index + 2] | 1970;
        score.secs = array[index + 3] | 300;
        result.scores[i] = score;
    } 
    return result;
}