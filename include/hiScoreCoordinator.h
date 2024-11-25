#ifndef HI_SCORE_COORDINATOR_H
#define HI_SCORE_COORDINATOR_H

#include "file/hiScoresFileManager.h"

/*
    Class for coordinating high scores. Loads high scores from sd once
    and keeps them cached. 
*/
class HiScoreCoordinator{

    private:

        // Object to provide file access functions
        HiScoresFileManager hiScoresFileManager;

        // Holds cached high scores
        HiScores hiScores;
        bool isSDMounted;
        bool isLoaded;

        void loadScores();
        int checkIfHiScore(Score score);
        void updateHiScores(int position, Score score); 
        void saveScores();


    public:

        HiScoreCoordinator(bool isSDMounted);
        HiScores getHiScores();

        // Public function called with endgame score, returns -1 if not high score else high score position
        int saveIfHiScore(Score score);
        void resetScores();

};

#endif