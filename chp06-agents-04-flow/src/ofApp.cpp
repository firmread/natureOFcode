#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(640, 360);
    ofEnableSmoothing();
    ofBackground(255);
    
    flowfield.setup(20);
    vehicles.resize(250);
    
    for (unsigned int i = 0; i < vehicles.size(); i++){
      
        ofVec2f location(ofGetWidth(), ofGetHeight());
        
        vehicles[i].setup(location, ofRandom(2,5), ofRandom(0.01,0.3));
   
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].follow(flowfield);
        vehicles[i].update();
        vehicles[i].borders();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (isDebugMode){
        flowfield.draw();
    }
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].draw();
    }
  
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        isDebugMode = !isDebugMode;
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
    flowfield.init();

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