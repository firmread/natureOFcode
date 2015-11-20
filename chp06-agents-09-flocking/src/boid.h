#pragma once
#include "ofMain.h"

class boid {
    
public:
    void setup(int x, int y);
    
    void update();
    
    void applyForce(const ofPoint & force);
    
    // We accumulate a new acceleration each time based on three rules
    void flock(vector<boid> boids);
    
  
    ofPoint separate (vector<boid> boids);            
    
    
    // Alignment
    // For every nearby boid in the system, calculate the average velocity
    ofPoint align (vector<boid> boids);
    
    // Cohesion
    // For the average location (i.e. center) of all nearby boids, calculate steering vector towards that location
    ofPoint cohesion (vector<boid> boids);
    
    // Wraparound
    void borders();
    
   
    
    
    // A method that calculates a steering force towards a target
    // STEER = DESIRED MINUS VELOCITY
    ofPoint seek(const ofPoint & target);
    
    void draw();
    
    
       
    const ofPoint& getLocation() const{
        return location;
    }
    
    const ofPoint& getVelocity() const{
        return velocity;
    }
    
private:
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float r;
    float maxForce;
    float topSpeed;
    
};
