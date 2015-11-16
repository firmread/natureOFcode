#pragma once

#include "ofMain.h"

class Vehicle{

public:
    vector <ofVec2f> history;
  
    
    void setup(int x, int y);
    void applyForce(const ofVec2f & force);
    void seek(const ofVec2f & target);
    void arrive(const ofVec2f & target);
    void boundaries();
    void circleBoundaries(float cR, ofVec2f cL);
    void update();
    void draw();
    
    
private:
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f futureLocation;
    ofVec2f predict;
    
    float topSpeed;
    float maxForce; 
    int r, cor;


    float d;
    ofVec2f circleLocation;
    float radius;
};