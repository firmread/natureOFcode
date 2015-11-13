// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Simple Harmonic Motion


#include "testApp.h"

void testApp::setup(){

    ofSetFrameRate(30);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    
}

void testApp::update(){ }


void testApp::draw(){

    ofBackground(255);
    
    float period = 120;
    float amplitude = 300;
    // Calculating horizontal location according to formula for simple harmonic motion
    float x = amplitude * cos(TWO_PI * ofGetFrameNum() / period);
    ofSetLineWidth(2);
    ofSetColor(127);
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofLine(0,0,x,0);
    // I have no idea why 'x' doesn't align the 'line' and the circle
    ofCircle(x * 0.9,0,24,24);
}


void testApp::mouseMoved(int x, int y ){

}

void testApp::keyPressed(int key){

}

void testApp::keyReleased(int key){

}

void testApp::mouseDragged(int x, int y, int button){

}

void testApp::mousePressed(int x, int y, int button){

}

void testApp::mouseReleased(int x, int y, int button){

}

void testApp::windowResized(int w, int h){

}

void testApp::gotMessage(ofMessage msg){

}

void testApp::dragEvent(ofDragInfo dragInfo){

}





