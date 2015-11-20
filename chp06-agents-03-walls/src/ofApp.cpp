#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofSetCircleResolution(100);
    ofSetVerticalSync(true);
    
    v.setup(ofGetWidth()/2, ofGetHeight()/2);
    d = 60;
    toggle = false;
    
    circleRadius = ofGetHeight()/2-d;
}

//--------------------------------------------------------------
void ofApp::update(){
    circlePosition.set(ofGetWidth()/2, ofGetHeight()/2);

    
    if(toggle){ v.boundaries();}
    else{
     v.circleBoundaries(circleRadius, circlePosition);
    }
    
    v.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    v.draw();
    
    
    if(toggle){
        
        ofSetColor(175);
        ofNoFill();
        ofRectMode(CENTER);
        ofRect(d, d, ofGetWidth()-d*2, ofGetHeight()-d*2);
    
    }
    
    
    else{
        ofSetColor(175);
        ofNoFill();
        ofCircle(circlePosition, circleRadius);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofBackground(255);
    
    toggle = !toggle;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}