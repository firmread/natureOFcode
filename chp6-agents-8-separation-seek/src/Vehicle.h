#pragma once

#include "ofMain.h"

class Vehicle{

public:
    ofVec2f location;
  
    void setup(int x, int y);
    void applyForce(const ofVec2f & force);
    ofVec2f seek(const ofVec2f & target);
    ofVec2f separate(vector<Vehicle> vehicles);
    void applyBehaviours(vector<Vehicle> vehicles);
    void borders();
    void update();
    void draw();

    const ofVec2f& getLocation() const {
        return location;
    }
    
private:
    
    ofVec2f velocity;
    ofVec2f acceleration;

    float topSpeed;
    float maxForce; 
    int r, cor;
    
    
};