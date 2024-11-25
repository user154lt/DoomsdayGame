#include "hiScoreCoordinator.h"

HiScoreCoordinator::HiScoreCoordinator(bool isSDMounted) :
    hiScoresFileManager(),
    isSDMounted(isSDMounted),
    isLoaded(false)
{

}

HiScores HiScoreCoordinator::getHiScores(){
    if(!isLoaded){
        loadScores();
    }
    return hiScores;
}


void HiScoreCoordinator::loadScores(){
    HiScores defaultScores;
    hiScores = (isSDMounted) ? hiScoresFileManager.getHiScores() : defaultScores;
    isLoaded = true;
}


int HiScoreCoordinator::saveIfHiScore(Score score){
    int result = checkIfHiScore(score);
    if(result != -1){
       updateHiScores(result, score); 
    }
    return result;
}

int HiScoreCoordinator::checkIfHiScore(Score score){
    int result = -1;
    for(int i = 0; i < 5; i++){
        if(score.secs < hiScores.scores[i].secs){
            result = i;
            break;
        }
    }
    return result;
}

void HiScoreCoordinator::updateHiScores(int position, Score score){
    hiScores.scores[position] = score;
    saveScores();
}

void HiScoreCoordinator::saveScores(){
    if (isSDMounted) hiScoresFileManager.saveHiScores(hiScores);
}

void HiScoreCoordinator::resetScores(){
    HiScores scores;
    hiScores = scores;
    saveScores();
}

