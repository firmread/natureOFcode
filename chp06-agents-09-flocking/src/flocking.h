#pragma once
#include "ofMain.h"
#include "boid.h"

class flocking{

private:
    vector<boid> boids;
 
public:
    void setup();
    void update();
    void draw();
    void addBoid(int x, int y);
};
    
