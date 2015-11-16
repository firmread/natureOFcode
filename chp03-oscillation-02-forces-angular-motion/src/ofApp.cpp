#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    float x = ofGetWidth();
    float y = ofGetHeight();
    
    for (int i = 0; i < 20; i++) {
        mover m = mover(ofRandom(1.0,3.0),ofRandom(0,x),ofRandom(0,y));
        movers.push_back(m);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < movers.size(); i++) {
        ofPoint force = a.attract(movers[i]);
        movers[i].applyForce(force);
        movers[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    a.display();
    
    for (int i = 0; i < movers.size(); i++) {
        movers[i].display();
    }
    cout << movers[0].angle << endl;
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