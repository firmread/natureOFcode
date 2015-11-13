#pragma once
#include "ofMain.h"

class Flowfield{

private:
    vector<vector<ofVec2f> > field;
    int cols, rows;
    int resolution;
    


public:
    void setup(int r);
    void init();
    void draw();
    void drawVector(const ofVec2f & v, float x, float y, float scayl);
    
    ofVec2f lookup(const ofVec2f & lookup) const;
    



};