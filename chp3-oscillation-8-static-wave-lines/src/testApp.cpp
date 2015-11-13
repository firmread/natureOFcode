// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// NOC_3_08 Static Sine Waves


#include "testApp.h"

void testApp::setup(){

    ofSetFrameRate(30);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);

    
}

void testApp::update(){ }


void testApp::draw(){

    ofBackground(255);
    ofNoFill();
    float angle = 0;
    float angleVel = 0.1;
    ofSetColor(0);
    ofBeginShape();
    for (int x = 0; x <= ofGetWidth(); x += 5) {
        float y = ofMap(sin(angle),-1,1,0,ofGetHeight());
        ofVertex(x,y);
        angle +=angleVel;
    }
    ofEndShape();
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

}

void testApp::mouseReleased(int x, int y, int button){

}

void testApp::windowResized(int w, int h){

}

void testApp::gotMessage(ofMessage msg){

}

void testApp::dragEvent(ofDragInfo dragInfo){

}





