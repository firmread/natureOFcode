#include "testApp.h"

/*
Openframewoks doesn't include a gaussian random generator. This example assumes that ofxGausisan is
installed. You can get it at http://github.com/andryr0id/ofxGaussian
*/

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    float xloc = ofxGaussian();
    
    float sd = 60;
    float mean = ofGetWidth()/2;
    
    xloc = (xloc * sd ) + mean;
    
    ofFill();
    ofColor col = ofColor(0,0,0,10);
    ofSetColor(col);
    
    ofCircle(xloc, ofGetHeight()/2, 16);

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