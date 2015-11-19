// learn more about C++ Pointer (*) at
// http://en.cppreference.com/w/cpp/language/pointer

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    
    p = new particle(ofPoint(ofGetWidth()/2, 20));

}

//--------------------------------------------------------------
void ofApp::update(){
    
    p->update();
    if(p->isDead()){
        p = new particle(ofPoint(ofGetWidth()/2, 20));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    p->display();
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
