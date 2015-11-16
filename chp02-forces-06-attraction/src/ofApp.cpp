// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Example 2-6: Attraction


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::update(){
    ofPoint force = a.attract(m);
    m.applyForce(force);
    m.update();
    
    a.drag();
    a.hover(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
    a.display();
    m.display();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    a.drag();
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    a.clicked(mouseX, mouseY);
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    a.stopDragging();
}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }