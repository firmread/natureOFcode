#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    
    bob.setup(ofGetWidth()/2, ofGetHeight()/2);
    spring.setup(ofGetWidth()/2, 50, 300);
    
    ofSetCircleResolution(1000);
    
    ofSetVerticalSync(true);
    

}

//--------------------------------------------------------------
void testApp::update(){
    
    ofVec2f gravity(0, 2);
    bob.applyForce(gravity);
    
    spring.connect(bob);
    spring.constrainLength(bob, 40, 200);
   
    bob.airResistance();
    
    
    
    
    
    
    bob.update();
    bob.drag(mouseX, mouseY);
    
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
    spring.display(bob);
    bob.display();

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
    bob.clicked(mouseX, mouseY);
    

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    bob.stopDragging();

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