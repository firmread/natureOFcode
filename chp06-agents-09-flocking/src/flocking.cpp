#include "flocking.h"

void flocking::setup(){
    boids.resize(100);
    for (auto & b: boids){
        b.setup(ofGetWidth()/2., ofGetHeight()/2);
    }
}

void flocking::update(){
    for (auto & b: boids){
        b.flock(boids);
        b.update();
        b.borders();
    }
}

void flocking::draw(){
    for (auto & b: boids){
        b.draw();
    }
}

void flocking::addBoid(int x, int y){
    boid v;
    v.setup(x, y);
    boids.push_back(v);
}