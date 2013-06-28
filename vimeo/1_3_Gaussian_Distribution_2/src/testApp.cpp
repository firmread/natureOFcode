#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofSetVerticalSync(true);
    //so it doesn't break vertically when math is faster than framerate
    ofSetCircleResolution(100);
    //nicer round circle :)
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
    float xloc = ofxGaussian();
    float sd = 60;
    float mean = ofGetWidth()/2;
    xloc = (xloc *sd) +mean;
    
    
    ofSetColor(0,10);
    ofCircle(xloc, ofGetHeight()/2, 8,8);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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