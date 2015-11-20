#ifndef DNA_H_INCLUDED
#define DNA_H_INCLUDED

#include <array>
#include <vector>
// #define GENE_COUNT 100
#include "ofMain.h"

class DNA
{

private:
    int lifetime;
    vector<ofPoint> genes;
    float maxforce = 0.1;

public:
    DNA() {};
    DNA(float _lifetime);
    vector<ofPoint> getGenes()
    {
        return genes;
    };
    DNA crossover(DNA partner);
    void mutate(float mutationRate);
    ofPoint randomDirection();
    void addGene(ofPoint gene);
};

#endif // DNA_H_INCLUDED
