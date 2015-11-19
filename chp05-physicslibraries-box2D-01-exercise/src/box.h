#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"

class box{
public:
    float w, h;
    ofxBox2dRect rect;
    
    box(float x, float y){
        w = 16;
        h = 16;
        
    }
    void display(){
        
    }
};