// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Example 2-8: Attraction


#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);     
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();

    float g = 0.4;
    for (int i=0;i<10;i++) {
        movers.push_back(Mover(ofRandom(0.1,2),ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),g));
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < movers.size(); i++) {
        for (int j = 0; j < movers.size(); j++) {
            if (i != j) {
                ofVec2f force = movers[j].attract(movers[i]);
                movers[i].applyForce(force);
            }
        }
        movers[i].update();
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