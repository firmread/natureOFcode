
#include "ofApp.h"
float angle = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(50);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(angle);
    
    ofSetColor(200);
    ofDrawLine(-50, 0, 50, 0);
    ofDrawCircle(50, 0, 8);
    ofDrawCircle(-50, 0, 8);

    // in OF, angles are in degrees
    angle += (0.05 / PI * 180.0);
}
//--------------------------------------------------------------

void ofApp::keyPressed(int key){ }
void ofApp::keyReleased(int key){ }
void ofApp::mouseMoved(int x, int y ){ }
void ofApp::mouseDragged(int x, int y, int button){ }
void ofApp::mousePressed(int x, int y, int button){ }
void ofApp::mouseReleased(int x, int y, int button){ }
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }
