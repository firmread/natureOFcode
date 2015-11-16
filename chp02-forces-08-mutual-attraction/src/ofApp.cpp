#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableSmoothing();
    ofEnableAlphaBlending();

    float g = 0.4;
    for (int i = 0; i < 10; i++) {
        mover m = mover(ofRandom(0.1,2),ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),g);
        movers.push_back(m);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < movers.size(); i++) {
        for (int j = 0; j < movers.size(); j++) {
            if (i != j) {
                ofPoint force = movers[j].attract(movers[i]);
                movers[i].applyForce(force);
            }
        }
        movers[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (auto&m: movers){
        m.display();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
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