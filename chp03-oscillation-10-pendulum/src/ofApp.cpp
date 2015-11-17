#include "ofApp.h"


void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(100);
    
    ofPoint init;
    init.set(ofGetWidth()/2, 0);
    p.setup(init, 500);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    p.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    p.display();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
void ofApp::keyReleased(int key){ }
void ofApp::mouseMoved(int x, int y ){ }
void ofApp::mouseDragged(int x, int y, int button){
    p.drag();
}

void ofApp::mousePressed(int x, int y, int button){
    p.clicked(mouseX, mouseY);
}

void ofApp::mouseReleased(int x, int y, int button){
    p.stopDragging();
}

void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }