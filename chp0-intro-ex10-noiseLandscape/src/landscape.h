
#pragma once

#include "ofMain.h"

class landscape {
    
public:
    int scl;
    int w, h;
    int rows, cols;
    float zoff;
    
    vector< vector<float> > z;
    //float z[][];
    //just like two-dimensional array
    
    landscape ();
    landscape (int _scl, int _w, int _h);
    void update();
    void draw();
};