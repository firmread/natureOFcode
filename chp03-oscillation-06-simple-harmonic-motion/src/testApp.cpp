// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// NOC_3_06 Simple Harmonic Motion


#include "testApp.h"

void testApp::setup(){

    ofSetFrameRate(30);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    
    angle = 0;
    aVelocity = 0.03;
    amplitude = 300;    
}

void testApp::update(){ }


void testApp::draw(){

    ofBackground(255);
    float x = amplitude * cos(angle);
    angle += aVelocity;
    ofSetColor(175);
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofLine(0,0,x,0);
    ofCircle(x* 0.9,0,20,20);
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





