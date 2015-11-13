#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include "ofMain.h"
#include "Perceptron.h"
#include "Target.h"

class Vehicle {

public:

    void update();
    void applyForce(ofVec2f force);
    ofVec2f seek(ofVec2f target);
    void steer(vector<Target> targets);
    void display();
    Vehicle() {}
    Vehicle(int n, float x, float y);

private:

    Perceptron brain;

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;

    float r;
    float maxforce;
    float maxspeed;

};

#endif // VEHICLE_H_INCLUDED
