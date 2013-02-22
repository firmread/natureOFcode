// Example 1-2: Bouncing Ball, with PVector!

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(200, 200);
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    ofBackground(255);
    ofSetBackgroundAuto(false);
	
    ofSetFrameRate(60);
    
    location.set(100,100);
    velocity.set(2.5, 5);
}

//--------------------------------------------------------------
void testApp::update(){
    // Add the current speed to the location.
    location += velocity;
    //aka: location = location + velocity
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableSmoothing();
    ofSetColor(255,10);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    if((location.x > ofGetWidth()) || (location.x < 0 )){
        velocity.x *= -1;
        //aka: velocity.x = velocity.x *-1;
    }
    if ((location.y > ofGetHeight()) || (location.y < 0 )){
        velocity.y *=-1;
    }
    
    // Display circle at x location
    ofSetColor(0);
    ofCircle(location.x, location.y, 8);
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