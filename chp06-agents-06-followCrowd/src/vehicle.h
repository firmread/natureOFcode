#pragma once

#include "ofMain.h"
#include "path.h"

class vehicle{

public:
    bool debug;
    
    void setup(ofPoint & l, float ts, float mf);
    void applyForce(const ofPoint & force);
    ofPoint follow(path & p);
    ofPoint getNormalPoint(ofPoint p, ofPoint a, ofPoint b);
    ofPoint seek(const ofPoint & target);
    ofPoint separate(vector<vehicle> vehicles);
    void applyBehaviours(vector<vehicle> vehicles, path & p);

    void borders();
    void update();
    void draw();
    
    const ofPoint& getLocation() const {
        return location;
    }
    
private:
    
    ofPoint predictLoc;
    ofPoint normal;
    ofPoint target;
    
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float maxSpeed;
    float maxForce; 
    int r, cor;
    
    float radius;
    float worldRecord;

};