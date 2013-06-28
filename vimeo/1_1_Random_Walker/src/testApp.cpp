#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    w.setup();
    ofSetBackgroundAuto(false);
    //this line is nessessary since OF automatically update background
    ofSetFrameRate(120);
    //limit cpu loop speed -> otherwise OF tends to use full power all the time
}

//--------------------------------------------------------------
void testApp::update(){
    w.walk();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0);
    w.render();
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