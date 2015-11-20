#pragma once
#include "ofMain.h"

class vehicle{
public:
    vector <ofPoint> history;
  
    void setup(int x, int y);
    void applyForce(const ofPoint & force);
    void seek(const ofPoint & target);
    void arrive(const ofPoint & target);
    void boundaries();
    void circleBoundaries(float cR, ofPoint cL);
    void update();
    void draw();
    
private:
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    ofPoint futureLocation;
    ofPoint predict;
    
    float maxSpeed;
    float maxForce; 
    int r, cor;

    float d;
    ofPoint circleLocation;
    float radius;
};