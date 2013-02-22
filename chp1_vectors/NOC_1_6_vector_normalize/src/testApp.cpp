/**
 * Normalize
 * Original Processing code by Daniel Shiffman.
 * OF rendition by firmread
 *
 * Demonstration of normalizing a vector.
 * Normalizing a vector sets its length to 1.
 */

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(800, 200);
    ofEnableSmoothing();
    
    ofBackground(255);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    // A vector that points to the mouse location
    ofPoint mouse(mouseX, mouseY);
    // A vector that points to the center of the window
    ofPoint center(ofGetWidth()/2,ofGetHeight()/2);
    
    // Subtract center from mouse which results in a vector that points from center to mouse
    mouse -= center;
    
    // Normalize the vector
    mouse.normalize();
    
    // Multiply its length by 50
    mouse *= 150;
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    // Draw the resulting vector
    ofSetColor(0);
    ofSetLineWidth(2);
    ofLine(0, 0, mouse.x, mouse.y);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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