#include "ofApp.h"

void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(100);
    ofSetFrameRate(60);

    startAngle = 0;
    angleVel = 0.2;
}

//--------------------------------------------------------------
void ofApp::update(){
    angleVel = ofMap(mouseX, 0, ofGetWidth(), 0.005, 0.5, true);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    startAngle += 0.015;
    float angle = startAngle;
    
    for (int x = 0; x <= ofGetWidth(); x += 24) {
        float y = ofMap(sin(angle), -1, 1, 0, ofGetHeight());
        
        ofSetColor(0, 30);
        ofDrawCircle(x,y,35);
       
        angle += angleVel;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
void ofApp::keyReleased(int key){ }
void ofApp::mouseMoved(int x, int y ){ }
void ofApp::mouseDragged(int x, int y, int button){ }
void ofApp::mousePressed(int x, int y, int button){ }
void ofApp::mouseReleased(int x, int y, int button){ }
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }