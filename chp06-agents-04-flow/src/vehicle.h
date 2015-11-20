#pragma once

#include "ofMain.h"
#include "flowField.h"

class vehicle{
public:
    vehicle(ofPoint & l, float ts, float mf);
    void applyForce(const ofPoint & force);
    void separate(vector<vehicle> vehicles);
    void borders();
    void update();
    void draw();
    void follow(const flowField & flow);

private:
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;

    float maxSpeed;
    float maxForce; 
    int r, cor;
    
};