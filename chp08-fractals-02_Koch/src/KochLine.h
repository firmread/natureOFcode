//
//  KochLine.h
//  Koch
//
//  Created by Charlie Whitney on 11/18/13.
//
//

#pragma once

#include "ofMain.h"

class KochLine {
  public:
    KochLine( ofVec2f _start, ofVec2f _end );
    void draw();
    
    float getLength();
    
    ofVec2f a();
    ofVec2f b();
    ofVec2f c();
    ofVec2f d();
    ofVec2f e();
    
    ofVec2f start, end;
};