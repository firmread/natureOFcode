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
    vector<ofVec2f> genes;
    float maxforce = 0.1;

public:
    DNA() {};
    DNA(float _lifetime);
    vector<ofVec2f> getGenes()
    {
        return genes;
    };
    DNA crossover(DNA partner);
    void mutate(float mutationRate);
    ofVec2f randomDirection();
    void addGene(ofVec2f gene);
};

#endif // DNA_H_INCLUDED
