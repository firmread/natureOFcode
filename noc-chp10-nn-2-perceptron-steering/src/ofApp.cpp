#include "ofApp.h"

#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetBackgroundAuto(true);

    vehicle = Vehicle(targetCount,ofGetWidth()/3,ofGetHeight()/4);

    for(int i = 0; i < targetCount; i++){
        targets.push_back(Target());
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    vehicle.steer(targets);
    vehicle.update();

    for(int i = 0; i < targets.size(); i++){
        targets[i].display();
    }
    vehicle.display();
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
