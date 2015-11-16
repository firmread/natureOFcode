#include "testApp.h"
#include "Pendulum.h"

Pendulum p;


//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofSetVerticalSync(true);
    
    ofVec2f init;
    init.set(ofGetWidth()/2, 10);
    
    p.setup(init, 500);
    
    ofSetCircleResolution(600);

}

//--------------------------------------------------------------
void testApp::update(){
    p.update();
    p.drag();
}

//--------------------------------------------------------------
void testApp::draw(){
    p.display();

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
    p.clicked(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    p.stopDragging();
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