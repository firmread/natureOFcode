#pragma once
#include "ofMain.h"

class path{

public:
    vector<ofPoint> points;
    float radius;
    

    void setup();
    void addPoint(float x, float y);
    void draw();
    
    


};