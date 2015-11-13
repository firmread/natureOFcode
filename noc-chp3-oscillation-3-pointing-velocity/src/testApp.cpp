// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Example 3_03 Pointing Velocity


#include "testApp.h"

void testApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
        
}

void testApp::update(){ }


void testApp::draw(){
    ofBackground(255);
    mover.update();
    mover.checkEdges();
    mover.display();
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





