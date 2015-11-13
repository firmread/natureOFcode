// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Example 2 Forces_Many_Attraction_3D


#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);     
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    
    a = new Attractor();
    angle = 0;
    float g = 0.4;
    for (int i=0;i<10;i++) {
        movers.push_back(Mover(ofRandom(0.1,2),ofRandom(ofGetWidth()/2),ofRandom(ofGetHeight()/2),ofRandom(-100,100),g));
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotateY(angle);

    a->display();
    for (int i = 0; i < movers.size(); i++) {
        ofVec3f force = a->attract(movers[i]);
        movers[i].applyForce(force);
        movers[i].update();
        movers[i].display();
    }
    
    angle += 0.003;
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