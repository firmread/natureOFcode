#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    
    ofVec2f initPos(0, ofGetHeight()/2);
    car1.setup(initPos, 3, 0.1);
    car2.setup(initPos, 5, 0.2);
    
    newPath();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    car1.follow(path);
    car2.follow(path);
    
    car1.update();
    car2.update();
    
    car1.borders();
    car2.borders();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    path.draw();

    car1.draw();
    car2.draw();
}


//--------------------------------------------------------------
void ofApp::newPath(){
    path.setup();
    path.addPoint(0, ofGetHeight()/2);
    path.addPoint(ofRandom(0, ofGetWidth()/2), ofRandom(0, ofGetHeight()));
    path.addPoint(ofRandom(ofGetWidth()/2, ofGetWidth()), ofRandom(0, ofGetHeight()));
    path.addPoint(ofGetWidth(), ofGetHeight()/2);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        car1.debug = !car1.debug;
        car2.debug = !car2.debug;
    }

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
    ofBackground(255);
    newPath();


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