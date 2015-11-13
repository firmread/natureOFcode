#include "Target.h"

Target::Target(){
    location = ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
}

void Target::display(){
    ofSetColor(0,0,0);
    ofCircle(location.x,location.y,22);
    ofSetColor(127,127,127);
    ofCircle(location.x,location.y,20);
}
