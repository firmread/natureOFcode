#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofSetVerticalSync(true);
    //so it doesn't break vertically when math is faster than framerate
    ofSetCircleResolution(100);
    //nicer round circle :)
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float xloc = ofxGaussian();
    float sd = 60;
    float mean = ofGetWidth()/2;
    xloc = (xloc *sd) +mean;
    
    
    ofSetColor(0,10);
    ofCircle(xloc, ofGetHeight()/2, 8,8);
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
