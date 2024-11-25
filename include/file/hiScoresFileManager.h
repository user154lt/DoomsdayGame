#ifndef HISCORES_FILE_H
#define HISCORES_FILE_H

#include <FS.h>
#include "file/hiScoresJson.h"

// Class providing functions for managing high scores file on sd card
class HiScoresFileManager{
    
    private:
        const char * DIR_PATH = "/doomsday";
        const char * FILE_PATH = "/doomsday/scores.json";

        HiScoresJson hiScoresJson;

        HiScores readFile(fs::FS &fs);
        void saveFile(fs::FS &fs, HiScores hiScores);
        void createDir(fs::FS &fs);

    public:

        HiScoresFileManager();
        HiScores getHiScores();
        void saveHiScores(HiScores hiScores);

};


#endif