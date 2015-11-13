#pragma once
#include "ofMain.h"

class Path{

public:
    vector<ofVec2f> points;
    float radius;
    

    void setup();
    void addPoint(float x, float y);
    void draw();
    
    


};