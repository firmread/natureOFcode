#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(true);
    ofVec2f startPoint = ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    tree = Tree(100.0,175.0,startPoint);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec2f startPoint = ofVec2f(ofGetWidth()/2,2 * ofGetHeight()/3);
    tree = Tree(90,ofMap(sin(ofGetFrameNum() * 0.001),-1,1,0,360),startPoint);
}

//--------------------------------------------------------------
void ofApp::draw(){
    tree.display();
    /*
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/-2);
    ofRotate(75);
    tree.display();
    ofPopMatrix();
    */
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
