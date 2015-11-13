#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofSetFrameRate(30);
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    
    //research whoy enabling depth test creates artifacts int he lines, proibably we will ened ofMesh?
    glEnable(GL_DEPTH_TEST);
    
    land = Landscape(20,800,400);
}

//--------------------------------------------------------------
void testApp::update(){
    land.calculate();
    theta += 0.0025;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2,-160);
        //ofRotate receives degrees instead of radians
        ofRotateX(ofRadToDeg(PI/3));
        ofRotateZ(ofRadToDeg(theta));
        land.render();
    ofPopMatrix();
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