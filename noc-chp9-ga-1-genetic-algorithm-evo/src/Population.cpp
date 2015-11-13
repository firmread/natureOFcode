#include "Population.h"
#include <iostream>

Population::Population()
{
    for (int i = 0; i < popSize; i++)
    {
        population[i] = DNA();
    }
}

void Population::calcFitness()
{
    int currentWinPos = 0;
    float highScore = 0.0;
    for (int i = 0; i < popSize; i++)
    {
        population[i].setWinner(false);
        float f = population[i].calcFitness();
        if(f > highScore) {
                currentWinPos = i;
                highScore = f;
        }
    }
    population[currentWinPos].setWinner(true);
    string bestPhrase(population[currentWinPos].getGenes());

   std::stringstream ss;
    ss << "Best so far:  " << bestPhrase << " Highest match score: " << highScore << std::endl;

    std::cout << ss.str();

}

void Population::createMatingPool()
{
    matingPool.clear();
    for (int i = 0; i < popSize; i++)
    {
        // n is equal to fitness times 100, which leaves us with an integer between 0 and 100.
        int n = population[i].getFitness() * 100;
        for (int j = 0; j < n; j++)
        {
            // Add each member of the population to the mating pool N times.
            matingPool.push_back(population[i]);
        }
    }
}

void Population::reproduce() {
  for (int i = 0; i < popSize; i++) {
    int a = ofRandom(matingPool.size());
    int b = ofRandom(matingPool.size());
    DNA partnerA = matingPool[a];
    DNA partnerB = matingPool[b];
    //Step 3a: Crossover
    DNA child = partnerA.crossover(partnerB);
    //Step 3b: Mutation
    child.mutate(mutationRate);
    //Note that we are overwriting the population with the new children. When draw() loops, we will perform all the same steps with the new population of children.
    population[i] = child;
  }
}
