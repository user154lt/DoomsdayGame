#ifndef HI_SCORES_JSON_H
#define HI_SCORES_JSON_H

#include <string>
#include "file/hiScores.h"

/*
    Very simple wrapper for ArudinoJson library. Converts json strings to high scores and vice versa.
    json file is just one long array. New score objects begin every 4 items.
*/
class HiScoresJson{
    public:
        std::string jsonFrom(HiScores hiScores);
        HiScores scoresFrom(std::string json);
        
};

#endif