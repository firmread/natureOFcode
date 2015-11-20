#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include "ofMain.h"

class Vehicle {

public:

    void update();
    void wander(ofPoint);
    void applyForce(ofPoint force);
    void seek(ofPoint target);
    void arrive(ofPoint target);
    void display();
    Vehicle() {}
    Vehicle(float x, float y);

private:

    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    ofPoint targetRelative;

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
