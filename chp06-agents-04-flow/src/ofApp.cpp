#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofBackground(255);
    
    ff.setup(25);
    
    for (int i = 0; i < 100; i++){
        ofPoint location(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        vehicles.push_back(new vehicle(location, ofRandom(2,5), ofRandom(0.01,0.3)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (auto & v : vehicles){
        v->follow(ff);
        v->update();
        v->borders();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (auto & v : vehicles){
        v->draw();
    }
    
    if (isDebugMode){
        ff.draw();
    }
  
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        isDebugMode = !isDebugMode;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ff.init();
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }