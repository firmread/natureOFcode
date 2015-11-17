// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// PolarToCartesian

// Convert a polar coordinate (r,theta) to cartesian (x,y):
// x = r * cos(theta)
// y = r * sin(theta)


#include "ofApp.h"

void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofSetCircleResolution(100);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();

    r = ofGetHeight() * 0.45;
    theta = 0;
    
}

void ofApp::update(){ }


void ofApp::draw(){

    // Translate the origin point to the center of the screen
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    // Convert polar to cartesian
    float x = r * cos(theta);
    float y = r * sin(theta);
    

    ofSetLineWidth(2);
    ofSetColor(0);
    ofDrawLine(0,0,x,y);

    ofSetColor(127);
    ofDrawCircle(x, y, 24, 24);
    
    // Increase the angle over time
    theta += 0.02;
    
}

void ofApp::mouseMoved(int x, int y ){ }
void ofApp::keyPressed(int key){ }
void ofApp::keyReleased(int key){ }
void ofApp::mouseDragged(int x, int y, int button){ }
void ofApp::mousePressed(int x, int y, int button){ }
void ofApp::mouseReleased(int x, int y, int button){ }
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }