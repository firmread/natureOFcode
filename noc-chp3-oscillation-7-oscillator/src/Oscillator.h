






#pragma once
#include "ofMain.h"

class Oscillator  {
    
    
public:
    void setup(int y);
    void oscillate();
    void display();
    
private:
    ofVec2f angle;
    ofVec2f velocity;
    ofVec2f amplitude;
    
    
    
   
};