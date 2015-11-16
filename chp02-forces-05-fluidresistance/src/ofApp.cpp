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
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofBackground(255);
    reset();
    
    myLiquid.setup(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2, 0.1);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i<NUM_MOVER; i++) {
        
        if (myLiquid.contains(movers[i])) {
            ofPoint dragForce = myLiquid.drag(movers[i]);
            movers[i].applyForce(dragForce);
        }
        
        ofPoint gravity(0, 0.1*movers[i].mass);
        
        movers[i].applyForce(gravity);
        
        movers[i].update();
        movers[i].checkEdges();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    myLiquid.display();
    for (int i = 0; i<NUM_MOVER; i++) {
        movers[i].display();
    }
}

//--------------------------------------------------------------

void ofApp::reset(){
    for (int i = 0 ; i < NUM_MOVER; i++) {
        movers[i].setup(ofRandom(0.5, 3), 40 + i*70, 0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'r'){
        reset();
    }
}
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
