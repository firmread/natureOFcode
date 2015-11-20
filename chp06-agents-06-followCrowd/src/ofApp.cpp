#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    
    ofPoint initPos(0, ofGetHeight()/2);
    vehicles.resize(15);
    
    for(auto & v : vehicles){
        ofPoint location(ofGetWidth(), ofGetHeight());
        v.setup(location, ofRandom(2,4), 0.3);
    }
    newPath();
}
//--------------------------------------------------------------
void ofApp::update(){
    for(auto & v : vehicles){
        v.applyBehaviours(vehicles, p);
        v.update();
        v.borders();
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    p.draw();
    for(auto & v : vehicles){
        v.draw();
    }
}
//--------------------------------------------------------------
void ofApp::newPath(){
    p.setup();
    p.addPoint(0, ofGetHeight()/2);
    p.addPoint(ofRandom(0, ofGetWidth()/2), ofRandom(0, ofGetHeight()));
    p.addPoint(ofRandom(ofGetWidth()/2, ofGetWidth()), ofRandom(0, ofGetHeight()));
    p.addPoint(ofGetWidth(), ofGetHeight()/2);
}


//--------------------------------------------------------------
void ofApp::newVehicle(float x, float y){
    float maxspeed = ofRandom(2,4);
    float maxforce = 0.3;
    ofPoint location(x,y);
    vehicle v;
    
    v.setup(location, maxspeed, maxforce);
    vehicles.push_back(v);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        newPath();
//        for(unsigned int i = 0; i < vehicles.size(); i++){
//            vehicles[i].debug = !vehicles[i].debug;
//        }
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofBackground(255);
    newVehicle(x, y);
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }