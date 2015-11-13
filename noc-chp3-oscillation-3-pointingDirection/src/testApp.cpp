// The Nature of Code
// Daniel Shiffman
//
// C++ / openFrameworks
// chapter 1 exercise 1.11
// version by Maria Paula Saba
// based on Emmanuel Geoffray
//

#include "testApp.h"
#include "mover.h"

vector<Mover> movers;


//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(640,360);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(255);
    
    movers.resize(1000);
    
    for(unsigned int i = 0; i < movers.size(); i++){
        movers[i].setup();
    }
    
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void testApp::update(){
    
    for(unsigned int i = 0; i < movers.size(); i++){
        movers[i].update();
        movers[i].checkEdges();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(unsigned int i = 0; i < movers.size(); i++){
        movers[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    ofVec2f mouse(x,y);
    
    for(unsigned int i = 0; i < movers.size(); i++){
        movers[i].setTarget(mouse, ofRandom(2));
    }
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