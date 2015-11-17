#include "ofApp.h"
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(255);
    ofSetCircleResolution(100);
    
    m.setup(ofGetWidth()/2, ofGetHeight()/2);
    sp.setup(ofGetWidth()/2, 30, 400);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofPoint gravity(0, 2);
    m.applyForce(gravity);
    
    sp.connect(m);
    sp.constrainLength(m, 40, 200);
   
//    m.airResistance();
    
    m.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    sp.display(m);
    m.display();
}

void ofApp::keyPressed(int key){ }
void ofApp::keyReleased(int key){ }
void ofApp::mouseMoved(int x, int y ){ }
void ofApp::mouseDragged(int x, int y, int button){
    m.drag(x, y);
}
void ofApp::mousePressed(int x, int y, int button){
    m.clicked(x, y);
}
void ofApp::mouseReleased(int x, int y, int button){
    m.stopDragging();
}
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }