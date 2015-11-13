// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// PolarToCartesian

// Convert a polar coordinate (r,theta) to cartesian (x,y):
// x = r * cos(theta)
// y = r * sin(theta)


#include "testApp.h"

void testApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);

    r = ofGetHeight() * 0.45;
    theta = 0;
    ofSetCircleResolution(50);
    
}

void testApp::update(){ }


void testApp::draw(){

    ofBackground(255);
    
    // Translate the origin point to the center of the screen
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    // Convert polar to cartesian
    float x = r * cos(theta);
    float y = r * sin(theta);
    

    ofSetLineWidth(2);
    ofNoFill();

    ofSetColor(0);
    ofLine(0,0,x,y);
    ofCircle(x, y, 24, 24);

    ofFill();
    ofSetColor(127);
    ofCircle(x, y, 24, 24);
    
    // Increase the angle over time
    theta += 0.02;
    
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





