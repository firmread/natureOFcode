#pragma once

#include "ofMain.h"

class Bob{

private:
 
    float mass = 24;
    float damping = 0.995;
    
    ofVec2f dragOffset;
    Boolean dragging = false;
    
    

    
public:
    
    void setup(float x, float y);
    void update();
    void applyForce(const ofVec2f & force);
    void display();
    void clicked(int mx, int my);
    void stopDragging();
    void drag(int mx, int my);
    void airResistance();
    

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
};