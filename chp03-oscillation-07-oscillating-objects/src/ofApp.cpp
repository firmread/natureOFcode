// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// NOC_3_07 Oscillating Objects
#include "ofApp.h"

void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableSmoothing();
    
    oscillators.resize(2);

}

void ofApp::update(){
    for (auto&o:oscillators) {
        o.oscillate();
    }
}


void ofApp::draw(){
    for (auto&o:oscillators) {
        o.display();
    }
}

void ofApp::mouseMoved(int x, int y ){ }
void ofApp::keyPressed(int key){
    if (oscillators.size() >0) oscillators.erase(oscillators.begin());
}
void ofApp::keyReleased(int key){ }
void ofApp::mouseDragged(int x, int y, int button){ }
void ofApp::mousePressed(int x, int y, int button){
    oscillator o;
    oscillators.push_back(o);
}
void ofApp::mouseReleased(int x, int y, int button){ }
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }