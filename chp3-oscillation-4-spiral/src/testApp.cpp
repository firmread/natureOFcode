#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    
    circles.resize(1);
    
    for(int i = 0; i < circles.size(); i++){
        circles[i].setup();
        
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < circles.size(); i++){
        circles[i].update();
    
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i = 0; i < circles.size(); i++){
        circles[i].draw();
        
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