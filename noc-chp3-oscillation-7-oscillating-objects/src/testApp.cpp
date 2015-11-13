// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// NOC_3_07 Oscillating Objects


#include "testApp.h"

void testApp::setup(){

    ofSetFrameRate(30);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    
    for (int i=0;i<10;i++) {
        oscillators.push_back(Oscillator());
    }

}

void testApp::update(){ }


void testApp::draw(){

    for (int i=0;i<oscillators.size();i++) {
        oscillators[i].oscillate();
        oscillators[i].display();
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

}

void testApp::mouseReleased(int x, int y, int button){

}

void testApp::windowResized(int w, int h){

}

void testApp::gotMessage(ofMessage msg){

}

void testApp::dragEvent(ofDragInfo dragInfo){

}





