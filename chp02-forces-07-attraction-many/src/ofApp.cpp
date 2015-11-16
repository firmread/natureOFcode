// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Example 2-7: Attraction


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableSmoothing();
    ofEnableAlphaBlending();

    for (int i=0;i<10;i++) {
        movers.push_back(mover());
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    a.hover(mouseX,mouseY);
    
    for (int i=0;i<movers.size();i++) {
        ofPoint force = a.attract(movers[i]);
        movers[i].applyForce(force);
        movers[i].update();
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    a.display();
    //C++11 syntax to call for each member in vector
    for (auto& m: movers){
        m.display();
    }
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