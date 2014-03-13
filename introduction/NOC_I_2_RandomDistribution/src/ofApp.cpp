#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    ofSetFrameRate(60);
    cout<<  sizeof(randomCounts) << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    int index = int(ofRandom((sizeof(randomCounts)/sizeof(*randomCounts))));
    randomCounts[index]++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
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
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }
