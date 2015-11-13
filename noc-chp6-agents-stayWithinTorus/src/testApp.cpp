// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

//  Stay Within Torus
//  Ported to OF by Jason McDermott


#include "testApp.h"

void testApp::setup(){

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

void testApp::update(){

    glEnable(GL_BLEND);
//    ofEnableAlphaBlending();
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glBlendFunc(GL_ONE, GL_ONE);
}


void testApp::draw(){

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

void testApp::mouseMoved(int x, int y ){

}

void testApp::keyPressed(int key){

}

void testApp::keyReleased(int key){

}

void testApp::mouseDragged(int x, int y, int button){

}

void testApp::mousePressed(int x, int y, int button){
  debug = !debug;
}

void testApp::mouseReleased(int x, int y, int button){

}

void testApp::windowResized(int w, int h){

}

void testApp::gotMessage(ofMessage msg){

}

void testApp::dragEvent(ofDragInfo dragInfo){

}





