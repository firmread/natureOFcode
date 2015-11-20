#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofSetCircleResolution(100);
    
    v.setup(ofGetWidth()/2, ofGetHeight()/2);
    d = 60;
    bSimpleBound = false;
    
    circleRadius = ofGetHeight()/2-d;
}

//--------------------------------------------------------------
void ofApp::update(){
    circlePosition.set(ofGetWidth()/2, ofGetHeight()/2);

    if(bSimpleBound){
        v.boundaries();
    }else{
        v.circleBoundaries(circleRadius, circlePosition);
    }
    v.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    v.draw();
    ofNoFill();
    if(bSimpleBound){
        ofSetColor(175);
        ofRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(d, d, ofGetWidth()-d*2, ofGetHeight()-d*2);
    }else{
        ofSetColor(175);
        ofDrawCircle(circlePosition, circleRadius);
    }
    ofFill();
    
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
void ofApp::mousePressed(int x, int y, int button){
    bSimpleBound = !bSimpleBound;
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }