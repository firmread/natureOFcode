#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofSetCircleResolution(100);
    ofSetVerticalSync(true);
    
    v.setup(ofGetWidth()/2, ofGetHeight()/2);
    d = 60;
    toggle = false;
    
    circleRadius = ofGetHeight()/2-d;
}

//--------------------------------------------------------------
void testApp::update(){
    circlePosition.set(ofGetWidth()/2, ofGetHeight()/2);

    
    if(toggle){ v.boundaries();}
    else{
     v.circleBoundaries(circleRadius, circlePosition);
    }
    
    v.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    v.draw();
    
    
    if(toggle){
        
        ofSetColor(175);
        ofNoFill();
        ofRectMode(CENTER);
        ofRect(d, d, ofGetWidth()-d*2, ofGetHeight()-d*2);
    
    }
    
    
    else{
        ofSetColor(175);
        ofNoFill();
        ofCircle(circlePosition, circleRadius);
    }
    
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
    
    toggle = !toggle;

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