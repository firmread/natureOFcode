#include "GOLCell.h"

GOLCell::GOLCell(float x_, float y_, float w_) {
    x = x_;
    y = y_;
    w = w_;
    
    state = int(ofRandom(2));
    previous = state;
}

void GOLCell::savePrevious() {
    previous = state;
}

void GOLCell::newState(int s) {
    state = s;
}

void GOLCell::display() {
    ofFill();
    
    if (previous == 0 && state == 1){
        ofSetColor(0,0,255);
    }
    else if (state == 1){
        ofSetColor(0);
    }
    else if (previous == 1 && state == 0){
        ofSetColor(255,0,0);
    }
    else{
        ofSetColor(255);
    }

    ofDrawRectangle(x, y, w, w);
    
    ofNoFill();
    ofSetColor(0);
    ofDrawRectangle(x, y, w, w);
}