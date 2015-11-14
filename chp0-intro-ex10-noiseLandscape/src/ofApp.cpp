#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(30);
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    
    //research whoy enabling depth test creates artifacts int he lines, proibably we will ened ofMesh?
    glEnable(GL_DEPTH_TEST);
    
    land = Landscape(20,800,400);
}

//--------------------------------------------------------------
void ofApp::update(){
    land.calculate();
    theta += 0.0025;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2,-160);
        //ofRotate receives degrees instead of radians
        ofRotateX(ofRadToDeg(PI/3));
        ofRotateZ(ofRadToDeg(theta));
        land.render();
    ofPopMatrix();
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