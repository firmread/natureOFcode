#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofBackground(255);
    
    vehicles.resize(100);
    
    for (auto & v : vehicles){
        ofPoint location(ofGetWidth(), ofGetHeight());
        v.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
}
//--------------------------------------------------------------
void ofApp::update(){
    for (auto & v : vehicles){
        v.separate(vehicles);
        v.borders();
        v.update();
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    for (auto & v : vehicles){
        v.draw();
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    vehicle v;
    v.setup(mouseX, mouseY);
    vehicles.push_back(v);
}
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