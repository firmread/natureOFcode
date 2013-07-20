#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofSetFrameRate(60);
    cout<<  sizeof(randomCounts);

}

//--------------------------------------------------------------
void testApp::update(){
    int index = int(ofRandom((sizeof(randomCounts)/sizeof(*randomCounts))));
    randomCounts[index]++;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetLineWidth(2);

    int w = ofGetWindowWidth()/(sizeof(randomCounts)/sizeof(*randomCounts));
    
    for (int x = 0; x < (sizeof(randomCounts)/sizeof(*randomCounts)) ; x++) {
        ofFill();
        ofSetColor(127);
        ofRect(x*w,ofGetWindowHeight()-randomCounts[x],w-1,randomCounts[x]);
        
        ofNoFill();
        ofSetColor(0);
        ofRect(x*w,ofGetWindowHeight()-randomCounts[x],w-1,randomCounts[x]);
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