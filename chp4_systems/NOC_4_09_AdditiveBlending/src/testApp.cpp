#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);

    ofBackground(0);
    
    img.loadImage("texture.png");
    ps = new ParticleSystem(ofPoint(ofGetWidth()/2, 50), img);
}

//--------------------------------------------------------------
void testApp::update(){
    
    ps->update();

    for (int i = 0; i < 10; i++) {
        ps->addParticle();
    }
}

//--------------------------------------------------------------
void testApp::draw(){    
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