#pragma once
#include "ofMain.h"

class pendulum {
public:
    float ballRadius;
    bool dragging;
    
    void setup(ofPoint orig, float len);
    void update();
    void display();
    
    void drag();
    void clicked(int mx, int my);
    void stopDragging();
private:
    ofPoint location;
    ofPoint origin;
    float length;
    float angle;
    float velocity;
    float acceleration;
    float damping;

};