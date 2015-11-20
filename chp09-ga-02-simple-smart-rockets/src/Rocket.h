#include "ofMain.h"
#include "Obstacle.h"
#include "DNA.h"
#include <vector>

#ifndef ROCKET_H_INCLUDED
#define ROCKET_H_INCLUDED

class Rocket {

public:
    Rocket();
    Rocket(float lifetime);
    void display();
    void update();
    void applyForce(ofPoint);
    float calcFitness();
    float getFitness() { return fitness; };
    void setTarget(ofPoint t) { target = t; };
    ofPoint getTarget() { return target; };
    void run();
    Rocket mate(Rocket partner);
    void checkObstacles();

private:
    float r = 12.0;
    int geneCounter = 0;
    DNA dna;
    ofPoint target;
    float fitness;
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    vector<Obstacle> obstacles;
    bool stopped = false;


public:
    DNA getDNA() { return dna; };
    DNA* getDNAP() { return &dna; };
    void setDNA(DNA d) { dna = d; };
    void resetGeneCounter() { geneCounter = 0; };
    void setObstacles(vector<Obstacle> o) { obstacles = o; };

};

#endif // ROCKET_H_INCLUDED
