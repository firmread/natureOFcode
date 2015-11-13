// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// NOC_3_07 Stay Within 'Donut'
// Simply for the fun of it, the vehicle must steer within the lines of a donut.
//  Ported to OF by Jason McDermott


#include "testApp.h"

void testApp::setup(){

    ofSetFrameRate(30);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    ofSetCircleResolution(100);
    
    debug = true;
    circleLocation.set(ofGetWidth()/2,ofGetHeight()/2);
    circleRadiusOuter = 200;
    circleRadiusInner = 150;
    
//    for (int i=0;i<50;i++) {   // in case you'd like to see lots of these in action
        v.push_back(Vehicle(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight())));
//    }
    
    

}

void testApp::update(){

}


void testApp::draw(){

    ofBackground(255);
    if (debug) {
        ofNoFill();
        ofSetColor(175);
        ofCircle(circleLocation.x,circleLocation.y, circleRadiusOuter/2, circleRadiusOuter/2);
        ofCircle(circleLocation.x,circleLocation.y, circleRadiusInner/2, circleRadiusInner/2);
    }

    for (int i=0;i<v.size();i++) {
        if (debug) {
            v[i].drawFutureLocation();
        }
        v[i].outerBoundaries(circleLocation, circleRadiusOuter);
        v[i].innerBoundaries(circleLocation, circleRadiusInner);
        v[i].run();
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





