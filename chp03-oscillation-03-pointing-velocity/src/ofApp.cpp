#include "ofApp.h"

void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
        
}

void ofApp::update(){
    m.update();
    m.checkEdges();
}

void ofApp::draw(){
    m.display();
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





