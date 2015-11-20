// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

//  Stay Within Sphere
//  Ported to OF by Jason McDermott


#include "ofApp.h"

void ofApp::setup(){

    ofSetFrameRate(30);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
    debug = true;
    circleLocation.set(ofGetWidth()/2,ofGetHeight()/2, 0);
    circleRadius = 200;
    
    for (int i=0;i<200;i++) {   // in case you'd like to see lots of these in action
        v.push_back(Vehicle(ofGetWidth()/2,ofGetHeight()/2-5, ofRandom(-10,10), circleLocation, circleRadius));
    }
}

void ofApp::update(){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    ofEnableAlphaBlending();
}


void ofApp::draw(){

    ofBackground(0);
    for (int i=0;i<v.size();i++) {
        v[i].boundaries();
        v[i].run();
    }
    
    if (debug) {
        ofSetColor(200, 200);
        ofSphere(circleLocation.x,circleLocation.y,circleLocation.z, circleRadius * 0.6);
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





