// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Example 2-7: Attraction


#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);
    ofBackground(255);     
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();

    for (int i=0;i<10;i++) {
        movers.push_back(Mover());
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    a.drag();
    a.hover(ofGetMouseX(),ofGetMouseY());
    a.display();
    
    for (int i=0;i<movers.size();i++) {
        ofVec2f force = a.attract(movers[i]);
        movers[i].applyForce(force);
        movers[i].update();
        movers[i].display();
    }    
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
    a.clicked(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    a.stopDragging();
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