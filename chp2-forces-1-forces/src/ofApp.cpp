/**
 * Acceleration with Vectors
 * Original Processing code by Daniel Shiffman.
 * OF rendition by firmread
 *
 * Demonstration of the basics of motion with vector.
 * A "Mover" object stores location, velocity, and acceleration as vectors
 * The motion is controlled by affecting the acceleration (in this case towards the mouse)
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    ofBackground(255);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofPoint wind(0.01, 0);
    ofPoint gravity(0, 0.1);
    m.applyForce(wind);
    m.applyForce(gravity);
    
    m.update();
    m.checkEdges();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    m.display();
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
