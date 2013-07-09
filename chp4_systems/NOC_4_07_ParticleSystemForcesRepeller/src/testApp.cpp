#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    
    ps = new ParticleSystem(ofPoint(ofGetWidth()/2, 50));
    repeller = new Repeller(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
}

//--------------------------------------------------------------
void testApp::update(){
    ps->addParticle();
    
    ofPoint gravity = *new ofPoint(0,0.1);
    ps->applyForce(gravity);
    ps->applyRepeller(*repeller);
    
    ps->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    repeller->display();
    ps->display();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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