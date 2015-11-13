#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofBackground(255);
     ofSetBackgroundAuto(true);
     wind.set(0.01,0.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    float noise = ofNoise(ofGetFrameNum()/50.0);
    float windSpeed = ofMap(noise,0.0,1.0,-0.1,0.1);
    wind = ofVec2f(windSpeed, 0.0);
    balloon.applyForce(wind);
    balloon.applyForce(gravity);
    balloon.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    balloon.display();
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
    balloon.setPosition(mouseX,mouseY);
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
