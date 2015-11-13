#include "DNA.h"

DNA::DNA()
{

    for (int i = 0; i < genesSize; i++)
    {
        genes[i] = (char)ofRandom(32,128);
    }
    // obviously shouldn't be hard coded, but ok for now
    target = "to be or not to be";
}

float DNA::calcFitness()
{
    int score = 0;
    for (int i = 0; i < genesSize; i++)
    {

        // Is the character correct?
        if (genes[i] == target.at(i))
        {
            //If so, increment the score.
            score++;
        }
    }

    fitness = float(score)/target.length();
    return fitness;
}

DNA DNA::crossover(DNA partner){
    DNA child = DNA();
    // Picking a random “midpoint” in the genes array
    int midpoint = ofRandom(genesSize);
    for (int i = 0; i < genesSize; i++) {
      // Before midpoint copy genes from one parent, after midpoint copy genes from the other parent
      if (ofRandom(1.0)>0.5) child.genes[i] = genes[i];
      else child.genes[i] = partner.genes[i];
    }
    //Return the new child DNA
    return child;
}

void DNA::mutate(float mutationRate) {
    for (int i = 0; i < genesSize; i++) {
      if (ofRandom(1) < mutationRate) {
        //Mutation, a new random character
        genes[i] = (char) ofRandom(32,128);
      }
    }
}

