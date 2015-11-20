#pragma once

#include "ofMain.h"

class vehicle{

public:
    ofPoint location;
  
    void setup(int x, int y);
    void applyForce(const ofPoint & force);
    void separate(vector<vehicle> vehicles);    
    void borders();
    void update();
    void draw();

    const ofPoint& getLocation() const {
        return location;
    }
    
private:
    
    ofPoint velocity;
    ofPoint acceleration;

    float topSpeed;
    float maxForce; 
    int r, cor;
    
    
};