// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// NOC_6 Stay Within Circle
// "Made-up" Steering behavior to stay within walls
//  Ported to OF by Jason McDermott


#include "ofApp.h"

void ofApp::setup(){

    ofSetFrameRate(30);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    ofSetCircleResolution(100);
    
    debug = true;
    circleLocation.set(ofGetWidth()/2,ofGetHeight()/2);
    circleRadius = 200;
    
//    for (int i=0;i<50;i++) {   // in case you'd like to see lots of these in action
        v.push_back(Vehicle(ofGetWidth()/2,ofGetHeight()/2-5,circleLocation, circleRadius));
//    }
    
    

}

void ofApp::update(){

}


void ofApp::draw(){

    ofBackground(255);
    if (debug) {
        ofNoFill();
        ofSetColor(175);
        ofCircle(circleLocation.x,circleLocation.y, circleRadius/2, circleRadius/2);
    }

    for (int i=0;i<v.size();i++) {
        v[i].boundaries();
        v[i].run();
    }

}



void ofApp::mouseMoved(int x, int y ){

}

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){
  debug = !debug;
}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){

}





