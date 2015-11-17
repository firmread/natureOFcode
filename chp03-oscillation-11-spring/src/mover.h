#pragma once
#include "ofMain.h"
class mover{
public:
    void setup(float x, float y);
    void update();
    void applyForce(const ofPoint & force);
    void display();
    void clicked(int mx, int my);
    void stopDragging();
    void drag(int mx, int my);
//    void airResistance();
    
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;

private:
    float mass;
    float damping;
    
    ofPoint dragOffset;
    bool dragging;

};