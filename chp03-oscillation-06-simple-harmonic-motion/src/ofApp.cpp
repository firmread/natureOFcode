// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// NOC_3_06 Simple Harmonic Motion
#include "ofApp.h"

void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableSmoothing();
    
    angle = 0;
    aVelocity = 0.03;
    amplitude = 300;    
}

void ofApp::update(){ }


void ofApp::draw(){

    float x = amplitude * sin(angle);
    angle += aVelocity;
    ofSetColor(127,200);
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofDrawLine(0, 0, x, 0);
    ofDrawCircle(x, 0, 24);
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