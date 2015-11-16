#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableSmoothing();
    ofSetFrameRate(60);
    /*
     try to set different framerates here to see how it affecting
     the speed of the ball. ex. 30,60,90,120 or try to commented it out.
     */
    
    x = 100;
    y = 100;
    xspeed = 2.5;
    yspeed = 2;
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //update void is for maths/other calculations
    
    // Add the current speed to the location.
    x = x + xspeed;
    y = y + yspeed;
    
    if ((x > ofGetWidth()) || (x < 0)) {
        xspeed = xspeed * -1;
    }
    if ((y > ofGetHeight()) || (y < 0)) {
        yspeed = yspeed * -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Display circle at x location
    
    //in OF lines and shapes have to be drawn separately
    //draw inside first
    ofSetColor(127);
    ofFill();
    ofDrawCircle(x, y, 24);
    
    //draw the outline
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(2);
    ofDrawCircle(x, y, 24);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }
