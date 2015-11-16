#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED

#include "Obstacle.h"
#include "Rocket.h"
#include "ofMain.h"
#include "DNA.h"
#include <vector>

class Population {

    public:

    Population();
    void calcFitness();
    void createMatingPool();
    void reproduce();
    void live();
    void run();
    void display();
    void displayTarget();
    void displayObstacles();

    private:

    ofVec2f target;
    static const int popSize = 100;
    Rocket population[popSize];
    vector<Rocket> matingPool;
    vector<Obstacle> obstacles;
    float mutationRate = 0.001;
    int generations;

    float lifetime = 1400;
    float lifeCounter = 0;

};

#endif // POPULATION_H_INCLUDED
