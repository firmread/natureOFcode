#pragma once

#include "ofMain.h"


class Pendulum {

public:
    float ballRadius;
    Boolean dragging;
    
    void setup(ofVec2f orig, float len);
    void update();
    void display();
    
    void drag();
    void clicked(int mx, int my);
    void stopDragging();
    
    
private:
    
    ofVec2f location;
    ofVec2f origin;
    float length;
    float angle;
    float velocity;
    float acceleration;
    float damping;
    

};