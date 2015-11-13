// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Example 3_02 Forces Angular Motion
// NOT WORKING CURRENTLY

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    time = 0;
    tick = 0.1;
    
    float x = ofGetWidth();
    float y = ofGetHeight();
    
    for (int i=0;i<20;i++) {
        movers.push_back(   Mover(ofRandom(0.1,2),ofRandom(0,x),ofRandom(0,y))   );
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    time += tick;

    if (time > 1) {
        for (int i = 0; i < movers.size(); i++) {
            ofVec2f force = a.attract(movers[i]);
            movers[i].applyForce(force);
            movers[i].update();
            movers[i].display();
        }
        time = 0;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);
    a.display();
    
    for (int i = 0; i < movers.size(); i++) {
        movers[i].display();
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
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





