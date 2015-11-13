
//
//  Flock.cpp
//  NOC_6_9_Flocking
//
//  Created by Maria Paula Saba dos Reis on 3/20/13.
//
//

#include "Flock.h"

void Flock::setup(){
    boids.resize(100);
    
    for (unsigned int i = 0; i < boids.size(); i++){
        boids[i].setup(ofGetWidth()/2., ofGetHeight()/2);
        
    }

}

void Flock::update(){
    
    for (unsigned int i = 0; i < boids.size(); i++){
        boids[i].flock(boids);
        boids[i].update();
        boids[i].borders();
    }
}

void Flock::draw(){
    for (unsigned int i = 0; i < boids.size(); i++){
        boids[i].draw();
    }
}

void Flock::addBoid(int x, int y){
    Boid v;
    v.setup(x, y);
    boids.push_back(v);
}