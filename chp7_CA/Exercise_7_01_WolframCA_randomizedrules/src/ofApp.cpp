
// The Nature of Code
// Daniel Shiffman
// OF version by Reed Tothong @firmread
// http://natureofcode.com

// Wolfram Cellular Automata

// Simple demonstration of a Wolfram 1-dimensional cellular automata
// When the system reaches bottom of the window, it restarts with a new ruleset
// Mouse click restarts as well



#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    delay = 0;
    ofBackground(255);
    int arr[] = {0,1,0,1,1,0,1,0};
    vector<int>ruleset (arr, arr+8);
    ca.ruleset = ruleset;
    ofSetFrameRate(30);
    ofSetBackgroundAuto(false);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw the CA
    ca.display();
    ca.generate();
    
    // If we're done, clear the screen, pick a new ruleset and restart
    if (ca.finished()) {
        delay++;
        if (delay > 30) {
            ca.randomize();
            ca.restart();
            delay = 0;
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
void ofApp::mousePressed(int x, int y, int button){
    ca.randomize();
    ca.restart();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }
