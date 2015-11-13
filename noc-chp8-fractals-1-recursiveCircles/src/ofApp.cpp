#include "ofApp.h"

void drawCircle(int x, int y, float radius) {
  ofSetColor(0,0,0);
  ofNoFill();
  ofCircle(x, y, radius);
  if(radius > 8) {
    // radius *= 0.75f;
    // The drawCircle() function is calling itself recursively.
    // drawCircle(x, y, radius);
    drawCircle(x + radius/2, y, radius/2);
    drawCircle(x - radius/2, y, radius/2);
    drawCircle(x, y + radius/2, radius/2);
    drawCircle(x, y - radius/2, radius/2);
  }
}


//--------------------------------------------------------------
void ofApp::setup(){
     ofBackground(255);
     ofSetBackgroundAuto(true);
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    drawCircle(ofGetWidth()/2,ofGetHeight()/2,ofGetWidth()/2.0);
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
