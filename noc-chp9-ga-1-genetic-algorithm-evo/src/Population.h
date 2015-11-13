#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED

#include "ofMain.h"
#include "DNA.h"
#include <vector>

class Population {

    public:

    Population();
    void calcFitness();
    void createMatingPool();
    void reproduce();

    private:

    static const int popSize = 100;
    DNA population[popSize];
    vector<DNA> matingPool;
    float mutationRate = 0.005;

};


#endif // POPULATION_H_INCLUDED
