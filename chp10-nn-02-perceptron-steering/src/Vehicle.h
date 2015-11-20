#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include "ofMain.h"
#include "Perceptron.h"
#include "Target.h"

class Vehicle {

public:

    void update();
    void applyForce(ofPoint force);
    ofPoint seek(ofPoint target);
    void steer(vector<Target> targets);
    void display();
    Vehicle() {}
    Vehicle(int n, float x, float y);

private:

    Perceptron brain;

    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;

    float r;
    float maxforce;
    float maxspeed;

};

#endif // VEHICLE_H_INCLUDED
