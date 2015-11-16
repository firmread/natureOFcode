#pragma once
#include "ofMain.h"
#include "Boid.h"


class Flock{

private:
    vector<Boid> boids;
 
public:
    void setup();
    void update();
    void draw();
    void addBoid(int x, int y);
};
    
