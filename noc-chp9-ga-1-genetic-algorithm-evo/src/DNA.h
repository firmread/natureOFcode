#ifndef DNA_H_INCLUDED
#define DNA_H_INCLUDED

#include "ofMain.h"

class DNA {

    private:

    static const int genesSize = 18;
    char genes[genesSize];
    float fitness;
    bool winner = false;

    public:

    DNA();
    float calcFitness();
    string target;
    float getFitness() { return fitness; };
    char* getGenes() { return genes; };

    DNA crossover(DNA partner);
    void mutate(float mutationRate);
    void setWinner(bool win) { winner = win; };


};

#endif // DNA_H_INCLUDED
