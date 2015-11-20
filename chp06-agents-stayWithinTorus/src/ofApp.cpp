// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

//  Stay Within Torus
//  Ported to OF by Jason McDermott


#include "ofApp.h"

void ofApp::setup(){

    ofSetFrameRate(30);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    glEnable(GL_DEPTH_TEST);
    
    debug = true;
    circleLocation.set(ofGetWidth()/2,ofGetHeight()/2, 0);
    circleRadiusOuter = 200;
    circleRadiusInner = 150;
    
    for (int i=0;i<2;i++) {   // in case you'd like to see lots of these in action
        v.push_back(Vehicle(ofGetWidth()/2,ofGetHeight()/2-5, ofRandom(-2,2)));
    }
}

void ofApp::update(){

    glEnable(GL_BLEND);
//    ofEnableAlphaBlending();
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glBlendFunc(GL_ONE, GL_ONE);
}


void ofApp::draw(){

    ofBackground(0);
    for (int i=0;i<v.size();i++) {
        v[i].outerBoundaries(circleLocation, circleRadiusOuter);
        v[i].innerBoundaries(circleLocation, circleRadiusInner);
        v[i].run();
    }
    
    if (debug) {
        ofSetColor(255,125);
        ofNoFill();
        ofCircle(circleLocation.x,circleLocation.y,circleRadiusOuter * 0.6);
        ofCircle(circleLocation.x,circleLocation.y,circleRadiusInner * 0.6);
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





