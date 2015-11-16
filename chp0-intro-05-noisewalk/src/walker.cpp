
#include "walker.h"

walker::walker() {
    // two ways to initialize ofPoint
    pos = ofPoint(0,0);
    noisePos.x = ofRandom(1000);
    noisePos.y = ofRandom(1000);
    
    scale = 1;
    noiseSpeed = 0.01;
}


void walker::update() {
    
    int rangeWidth = (ofGetWidth()/2) /scale;
    int rangeHeight = (ofGetHeight()/2) /scale;
    
    pos.x = ofMap(ofNoise(noisePos.x), 0, 1.0, -rangeWidth, rangeWidth);
    pos.y = ofMap(ofNoise(noisePos.y), 0, 1.0, -rangeHeight, rangeHeight);
    
    noisePos += ofPoint(noiseSpeed, noiseSpeed);

    // screen wrapping functions are not needed as noises are mapped with windows range
    
//    pos.x = overflow(pos.x, -rangeWidth, rangeWidth);
//    pos.y = overflow(pos.y, -rangeHeight, rangeHeight);
}


void walker::draw() {
    
    ofSetColor(255);
    ofDrawCircle(pos, 26);

    ofSetColor(ofColor::royalBlue);
    ofDrawCircle(pos, 25);
    
    ofSetColor(255, 2);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
}


int walker::constrain(int input, int min, int max) {
    return (input < min) ? min : ((input > max) ? max : input);
}


int walker::overflow(int input, int min, int max) {
    return (input < min) ? max : ((input > max) ? min : input);
}