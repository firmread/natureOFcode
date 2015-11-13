#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);

    osc.resize(1);
    
    for (unsigned int i = 0; i < osc.size(); i++) {
        osc[i].setup(50);
   
    }
    
    ofSetVerticalSync(true);

}

//--------------------------------------------------------------
void testApp::update(){
    for (unsigned int i = 0; i < osc.size(); i++) {
        osc[i].oscillate();
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (unsigned int i = 0; i < osc.size(); i++) {
        osc[i].display();
        
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
    Oscillator newOsc;
    newOsc.setup(50);
    osc.push_back(newOsc);

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