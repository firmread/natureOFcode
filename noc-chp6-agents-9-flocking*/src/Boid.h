#pragma once
#include "ofMain.h"

class Boid {
    
public:
    Boid();
    
    void setup(int x, int y);
    
    void update();
    
    void applyForce(const ofVec2f & force);
    
    // We accumulate a new acceleration each time based on three rules
    void flock(vector<Boid*> boids);
    
  
    ofVec2f separate (vector<Boid*> boids);
    
    
    // Alignment
    // For every nearby boid in the system, calculate the average velocity
    ofVec2f align (vector<Boid*> boids);
    
    // Cohesion
    // For the average location (i.e. center) of all nearby boids, calculate steering vector towards that location
    ofVec2f cohesion (vector<Boid*> boids);
    
    // Wraparound
    void borders();
    
   
    
    
    // A method that calculates a steering force towards a target
    // STEER = DESIRED MINUS VELOCITY
    ofVec2f seek(const ofVec2f & target);
    
    void draw();
    
    
       
    const ofVec2f& getLocation() const{
        return location;
    }
    
    const ofVec2f& getVelocity() const{
        return velocity;
    }
    
private:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float r;
    float maxForce;
    float topSpeed;
    
};
