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
    ofEnableAlphaBlending();
    ofBackground(255);
    
    for (int i = 0; i<NUM_MOVER; i++) {
        movers[i].setup(ofRandom(0.1,4), 0, 0);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    ofPoint wind(0.01, 0);
    ofPoint gravity(0, 0.1);
    
    for (int i = 0; i<NUM_MOVER; i++) {
        movers[i].applyForce(wind);
        movers[i].applyForce(gravity);
        
        movers[i].update();
        movers[i].checkEdges();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i<NUM_MOVER; i++) {
        movers[i].display();
    }
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
