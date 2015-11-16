#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    
    ps = new ParticleSystem(ofPoint(ofGetWidth()/2, 50));
    repeller = new Repeller(ofPoint(ofGetWidth()/2, ofGetHeight()/2));

}

//--------------------------------------------------------------
void ofApp::update(){
    ps->addParticle();
    
    ofPoint gravity = *new ofPoint(0,0.1);
    ps->applyForce(gravity);
    ps->applyRepeller(*repeller);
    
    ps->update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    repeller->display();
    ps->display();

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
