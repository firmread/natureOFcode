#pragma once
#include "ofMain.h"

class flowField{

private:
    vector<vector<ofPoint> > field;
    int cols, rows;
    int resolution;
public:
    void setup(int r);
    void init();
    void draw();
    void drawVector(const ofPoint & v, float x, float y, float scayl);
    
    ofPoint lookup(const ofPoint & lookup) const;
};