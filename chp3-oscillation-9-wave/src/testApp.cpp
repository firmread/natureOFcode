#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    float angle = startAngle;
    
    for (int x = 0; x <= ofGetWidth(); x += 24) {
        float y = ofMap(sin(angle), -1, 1, 100, ofGetHeight()-100);
        ofSetColor(0);
        ofNoFill();
        ofEllipse(x,y,48,48);
       
        
        ofSetColor(0, 50);
        ofFill();
        ofEllipse(x,y,48,48);
        
        angle += angleVel;
    }
    
    startAngle += 0.02;
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