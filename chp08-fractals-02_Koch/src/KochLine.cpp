//
//  KochLine.cpp
//  Koch
//
//  Created by Charlie Whitney on 11/18/13.
//
//

#include "KochLine.h"

KochLine::KochLine( ofVec2f _start, ofVec2f _end ){
    start = _start;
    end =  _end;
}

void KochLine::draw() {
    ofLine( start, end );
}

float KochLine::getLength() {
    return start.distance( end );
}

ofVec2f KochLine::a(){
    return start;
}

ofVec2f KochLine::b(){
    ofVec2f dir = (end - start) * 0.333333333;
    return (start + dir);
}

ofVec2f KochLine::c(){
    ofVec2f dir = (end - start) * 0.333333333;
    dir.rotate( -60 );
    
    return b() + dir;
}

ofVec2f KochLine::d(){
    ofVec2f dir = (end - start) * 0.666666667;
    return (start + dir);
}

ofVec2f KochLine::e(){
    return end;
}
