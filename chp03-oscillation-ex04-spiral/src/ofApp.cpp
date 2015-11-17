#include "ofApp.h"


void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    

}

//--------------------------------------------------------------
void ofApp::update(){
    float speed = ofMap(mouseX, 0, ofGetWidth(), 0.3, 10.0, true);
    c.update(speed);
}

//--------------------------------------------------------------
void ofApp::draw(){
    c.draw();
}

void ofApp::keyPressed(int key){
    c.reset();
}

void ofApp::keyReleased(int key){ }
void ofApp::mouseMoved(int x, int y ){ }
void ofApp::mouseDragged(int x, int y, int button){ }
void ofApp::mousePressed(int x, int y, int button){ }
void ofApp::mouseReleased(int x, int y, int button){ }
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }