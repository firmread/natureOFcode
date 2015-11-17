// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// NOC_3_08 Static Sine Waves


#include "ofApp.h"

void ofApp::setup(){

    ofSetFrameRate(30);
    ofBackground(255);
    ofEnableSmoothing();
    
}

void ofApp::update(){ }


void ofApp::draw(){

    ofNoFill();
    float angle = 0;
    float angleVel = 0.1;
    
    ofSetColor(0);
    ofBeginShape();
    for (int x = 0; x <= ofGetWidth(); x += 5) {
        float y = ofMap(sin(angle),-1,1,0,ofGetHeight());
        ofVertex(x,y);
        angle +=angleVel;
    }
    ofEndShape();
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