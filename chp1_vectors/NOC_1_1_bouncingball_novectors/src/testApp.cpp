// Example 1-1: Bouncing Ball, no vectors

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofEnableSmoothing();
    ofSetFrameRate(30);
    /*  
        try to set different framerates here to see how it affecting
        the speed of the ball. ex. 30,60,90,120 or try to commented it out.
    */
    
    x = 100;
    y = 100;
    xspeed = 2.5;
    yspeed = 2;
    ofBackground(255);
}

//--------------------------------------------------------------
void testApp::update(){
    //update void is for maths/other calculations
    
    // Add the current speed to the location.
    x = x + xspeed;
    y = y + yspeed;
    
    if ((x > ofGetWidth()) || (x < 0)) {
        xspeed = xspeed * -1;
    }
    if ((y > ofGetHeight()) || (y < 0)) {
        yspeed = yspeed * -1;
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Display circle at x location
    
    //in OF lines and shapes have to be drawn separately
    //draw inside first
    ofSetColor(127);
    ofFill();
    ofCircle(x, y, 24);
    
    //draw the outline
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(2);
    ofCircle(x, y, 24);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}