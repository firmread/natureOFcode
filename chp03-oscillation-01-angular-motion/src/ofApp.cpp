#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    angle = 0;
    aVelocity = 0;
    aAcceleration = 0.001;
    
}
//--------------------------------------------------------------
void ofApp::update(){
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(127);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(angle);
    ofSetColor(0);
    ofSetLineWidth(2);
    ofDrawLine(-60, 0, 60, 0);
    
    ofSetColor(127);
    ofDrawCircle(60, 0, 16, 16);
    ofDrawCircle(-60, 0, 16, 16);
    
    angle += aVelocity;
    aVelocity += aAcceleration;
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
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