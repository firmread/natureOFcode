#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(800, 300);
    ofEnableSmoothing();
    ofBackground(255);
    
    vehicles.resize(100);
    
    for (unsigned int i = 0; i < vehicles.size(); i++){
      
        ofVec2f location(ofGetWidth(), ofGetHeight());
        
        vehicles[i].setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
   
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].applyBehaviours(vehicles);
        vehicles[i].borders();
        vehicles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].draw();
    }
    cout << ofGetFrameRate() << endl;
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
 
    Vehicle v;
    v.setup(mouseX, mouseY);
    vehicles.push_back(v);
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