/**
 * Normalize
 * Original Processing code by Daniel Shiffman.
 * OF rendition by firmread
 *
 * Demonstration of normalizing a vector.
 * Normalizing a vector sets its length to 1.
 */


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableSmoothing();
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
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
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }
