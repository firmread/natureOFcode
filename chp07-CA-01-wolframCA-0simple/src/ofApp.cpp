// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// OF version by Reed Tothong @firmread
// Wolfram Cellular Automata

// Simple demonstration of a Wolfram 1-dimensional cellular automata

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(255);
}
//--------------------------------------------------------------
void ofApp::update(){

}
//--------------------------------------------------------------
void ofApp::draw(){
    if (ofGetFrameNum() > 2) {
        ca.display();
        if (ca.generation < ofGetHeight()/ca.w) {
            ca.generate();
        }
    }
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
