#include "ofApp.h"


void ofApp::setup(){
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(255);
    
    movers.resize(200);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(auto &m : movers){
        m.update();
        m.checkEdges();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto &m :movers){
        m.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
void ofApp::keyReleased(int key){ }

void ofApp::mouseMoved(int x, int y){
    ofPoint mouse(x,y);
    for(auto &m :movers){
        m.setTarget(mouse, ofRandom(2));
    }
}

void ofApp::mouseDragged(int x, int y, int button){ }
void ofApp::mousePressed(int x, int y, int button){ }
void ofApp::mouseReleased(int x, int y, int button){ }
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }