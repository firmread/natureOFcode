// The Nature of Code
// Daniel Shiffman
// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 
// TODO: add accumulative drawing
// TODO: draw stroke on circle

#include "testApp.h"

// Example 3-1: rotate baton

float angle = 0;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(200,200);
  ofEnableSmoothing();
  ofEnableAlphaBlending();
  ofBackground(50);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
  ofFill();
  ofSetColor(175);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  ofRotate(angle);
  ofLine(-50, 0, 50, 0);
  ofEllipse(50, 0, 8, 8);
  ofEllipse(-50, 0, 8, 8);

  // in oF, angles are in degrees
  angle += (0.05 / PI * 180.);
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
