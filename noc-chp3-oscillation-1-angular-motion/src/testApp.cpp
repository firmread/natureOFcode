// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Example 3 Angular Motion


#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    
    angle = 0;
    aVelocity = 0;
    aAcceleration = 0.001;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);
    ofSetColor(127);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(angle);
    ofSetColor(0);
    ofSetLineWidth(2);
    ofLine(-60, 0, 60, 0);
    
    
    ofNoFill();
    ofSetColor(0);
    ofCircle(60, 0, 16, 16);
    ofCircle(-60, 0, 16, 16);
    
    
    ofFill();
    ofSetColor(127);
    ofCircle(60, 0, 16, 16);
    ofCircle(-60, 0, 16, 16);
    
    angle += aVelocity;
    aVelocity += aAcceleration;
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}





