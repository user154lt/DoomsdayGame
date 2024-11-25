#ifndef HI_SCORES_H
#define HI_SCORES_H

// Data class for single score
typedef struct Score{
    int day = 1; 
    int month = 1;
    int year = 1970; 
    int secs = 300;
} Score;


// Data class representing a collection of 5 scores. Score 0 is the top score
typedef struct HiScores{
    
    Score scores[5];

    Score operator [] (int i){
        return scores[i];
    }

} HiScores;

#endif