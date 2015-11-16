#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(60);
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    
    //research whoy enabling depth test creates artifacts in the lines, probably we will end ofMesh?
    glEnable(GL_DEPTH_TEST);
    
    land = landscape(20,800,400);
}

//--------------------------------------------------------------
void ofApp::update(){
    land.update();
    float speed = ofMap(mouseX, 0, ofGetWidth(), 0.0001, 0.05, true);
    theta += speed;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2,-160);
        //ofRotate receives degrees instead of radians
        ofRotateX(ofRadToDeg(PI/3));
        ofRotateZ(ofRadToDeg(theta));
        land.draw();
    ofPopMatrix();
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