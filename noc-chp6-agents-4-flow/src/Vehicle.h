#pragma once

#include "ofMain.h"

class Vehicle{

public:
    
    void setup(ofVec2f & l, float ts, float mf);
    void applyForce(const ofVec2f & force);
    void separate(vector<Vehicle> vehicles);
    void borders();
    void update();
    void draw();
    
    
private:
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;

    float topSpeed;
    float maxForce; 
    int r, cor;
    
    
};