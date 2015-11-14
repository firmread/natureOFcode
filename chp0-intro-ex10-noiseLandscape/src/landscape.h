
#pragma once

#include "ofMain.h"

class Landscape {
    
    public:
    int scl;           // size of each cell
    int w, h;           // width and height of thingie
    int rows, cols;    // number of rows and columns
    float zoff = 0.0;  // perlin noise argument
    
    vector< vector<float> > z;
    //float z[][];       // using an array to store all the height values
    
    Landscape ();
    Landscape (int scl_, int w_, int h_);
    void calculate();
    void render();
};