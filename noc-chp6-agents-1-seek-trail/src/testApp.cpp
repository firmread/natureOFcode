#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    
    v.setup(ofGetWidth()/2, ofGetHeight()/2);
    
}

//--------------------------------------------------------------
void testApp::update(){
 
    ofVec2f mouse(mouseX, mouseY);
    v.seek(mouse);
    
    v.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    v.draw();
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
    ofBackground(255);
  ;

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