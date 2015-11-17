#include "ofApp.h"

void ofApp::setup(){
    ofBackground(255);
    ship.setup();
    isPressed = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ship.update();
    ship.checkEdges();
    
    if(isPressed)ship.thrust();
    if(isRight) ship.turn(-0.03);
    if(isLeft)  ship.turn(0.03);

}

//--------------------------------------------------------------
void ofApp::draw(){
    ship.draw();
}

void ofApp::keyPressed(int key){
    if (key == 'a' || key == 'A') isRight = true;
    if (key == 's' || key == 'S') isLeft = true;
}
void ofApp::keyReleased(int key){
    if (key == 'a' || key == 'A') isRight = false;
    if (key == 's' || key == 'S') isLeft = false;
}
void ofApp::mouseMoved(int x, int y ){ }
void ofApp::mouseDragged(int x, int y, int button){ }
void ofApp::mousePressed(int x, int y, int button){
    isPressed = true;
}

void ofApp::mouseReleased(int x, int y, int button){
    isPressed = false;
}
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }