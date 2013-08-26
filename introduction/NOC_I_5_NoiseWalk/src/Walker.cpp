//
//  Walker.cpp
//  NOC_I_1_RandomWalkTraditional
//
//  Created by Matthias Esterl on 7/7/13.
//  http://madcity.at
//

#include "Walker.h"

Walker::Walker() {
    location = ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    noff = ofPoint(ofRandom(1000), ofRandom(1000));
}

void Walker::display() {
    ofSetLineWidth(2);
    
    ofSetColor(127);
    ofFill();
    
    ofCircle(location, 24);
    
    ofSetColor(0);
    ofNoFill();
    
    ofCircle(location, 24);
}

void Walker::walk() {
    location.x = ofMap(ofNoise(noff.x),0, 1, 0, ofGetWindowWidth());
    location.y = ofMap(ofNoise(noff.y),0, 1, 0, ofGetWindowHeight());
    
    noff += ofPoint(0.01, 0.01);
}

int Walker::constrain(int amt, int low, int high) {
    /* http://forum.openframeworks.cc/index.php?topic=1413.0 */
    
    return (amt < low) ? low : ((amt > high) ? high : amt);
}