// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Example 2 Forces_Many_Attraction_3D


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);     
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    
    a = new attractor();
    angle = 0;
    float g = 0.4;
    for (int i=0;i<10;i++) {
        mover m = mover(ofRandom(0.1,2),ofRandom(ofGetWidth()/2),ofRandom(ofGetHeight()/2),ofRandom(-100,100),g);
        movers.push_back(m);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotateY(angle);

    a->display();
    for (int i = 0; i < movers.size(); i++) {
        ofPoint force = a->attract(movers[i]);
        movers[i].applyForce(force);
        movers[i].update();
        movers[i].display();
    }
    
    angle += 0.003;
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