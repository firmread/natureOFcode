#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetBackgroundAuto(true);
    angleDegrees = 0.0f;
}

//--------------------------------------------------------------
void ofApp::update(){
    angleDegrees += 0.03;
}

//--------------------------------------------------------------
void ofApp::draw(){

   ofTranslate(ofGetViewportWidth()/2.0f,ofGetViewportHeight()/2.0f);

     ofRotateZ(angleDegrees);

     ofSetColor(0,0,0);
     ofFill();
     ofLine(-50,0,50,0);
     ofCircle(50,0,10);
     ofCircle(-50,0,10);
     ofSetColor(175,175,175);
     ofCircle(50,0,8);
     ofCircle(-50,0,8);

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
