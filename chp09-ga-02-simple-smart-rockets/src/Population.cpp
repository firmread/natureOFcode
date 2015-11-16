#include "Population.h"
#include <iostream>

Population::Population()
{
    Obstacle obst = Obstacle(ofVec2f(ofGetWidth()/3,ofGetHeight()/2),ofVec2f(ofGetWidth()/3,15));
    obstacles.push_back(obst);

    target = ofVec2f(ofGetWidth()/2,50);
    for (int i = 0; i < popSize; i++)
    {
        population[i] = Rocket(lifetime);
        population[i].setTarget(target);
        population[i].setObstacles(obstacles);
    }
}

void Population::calcFitness()
{
    for (int i = 0; i < popSize; i++)
    {
        float f = population[i].calcFitness();

        std::stringstream ss;
        ss << "Fitness: " << f << std::endl;
        std::cout << ss.str();


    }
}

void Population::display(){
    for (int i = 0; i < popSize; i++)
    {
        population[i].display();
    }
}

void Population::createMatingPool()
{
    int prevPoolSize =  matingPool.size();
    if(prevPoolSize == 0 ) prevPoolSize = 10;
    matingPool.clear();

    float totalFitness = 0.0;
    for (int i = 0; i < popSize; i++)
    {
        totalFitness += population[i].getFitness();
    }
    float avgFitness = totalFitness/popSize;

    for (int i = 0; i < popSize; i++)
    {
        // n is equal to fitness times 100, which leaves us with an integer between 0 and 100.
        int n = population[i].getFitness() * 10 / avgFitness * 10;
        for (int j = 0; j < n; j++)
        {
            // Add each member of the population to the mating pool N times.
            matingPool.push_back(population[i]);
        }
    }
}

void Population::reproduce()
{

    std::stringstream ss;
    ss << "Mating Pool Size: " << matingPool.size() << std::endl;
    std::cout << ss.str();

    for (int i = 0; i < popSize; i++)
    {
        population[i].resetGeneCounter();

        int a = ofRandom(matingPool.size());
        int b = ofRandom(matingPool.size());
        Rocket partnerA = matingPool[a];
        Rocket partnerB = matingPool[b];
        //Step 3a: Crossover
        Rocket child = partnerA.mate(partnerB);
        //Step 3b: Mutation
        child.getDNAP()->mutate(mutationRate);
        //Note that we are overwriting the population with the new children. When draw() loops, we will perform all the same steps with the new population of children.
        population[i] = child;

    }
}

void Population::run() {
  if (lifeCounter < lifetime) {
    // Step 2: The rockets live their life until lifeCounter reaches lifetime.
    live();
    lifeCounter++;
  } else {
    // When lifetime is reached, reset lifeCounter and evolve the next generation (Steps 3 and 4, selection and reproduction).
    lifeCounter = 0;
    calcFitness();
    createMatingPool();
    reproduce();
  }
}


void Population::live()
{
    for (int i = 0; i < popSize; i++)
    {
        //The run function takes care of the forces, updating the rocket’s location, and displaying it.
        population[i].run();
    }
}

void Population::displayObstacles(){
    for(int i = 0; i < obstacles.size(); i++){
        obstacles[i].display();
    }
}

void Population::displayTarget(){
    int maxRadius = 20;
    for(int i = maxRadius; i >= 2; i -= 2) {
        if((i%4)==0){
            ofSetColor(255,0,0);
        } else {
            ofSetColor(0,0,0);
        }
        ofCircle(target.x,target.y,i);
    }
}
