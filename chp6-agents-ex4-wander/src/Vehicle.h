#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include "ofMain.h"

class Vehicle {

public:

    void update();
    void wander(ofVec2f);
    void applyForce(ofVec2f force);
    void seek(ofVec2f target);
    void arrive(ofVec2f target);
    void display();
    Vehicle() {}
    Vehicle(float x, float y);

private:

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f targetRelative;

    float r;
    float maxforce;
    float maxspeed;
    float arriveRadius;

    float targetDistance;
    float targetRadius;
    float alphaTargetAngle;
    float currentTargetAngle;

};

#endif // VEHICLE_H_INCLUDED
