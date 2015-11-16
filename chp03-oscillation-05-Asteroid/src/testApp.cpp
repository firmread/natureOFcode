#include "testApp.h"
#include "Spaceship.h"
Spaceship ship;

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ship.setup();
    isPressed = false;
    
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){
    ship.update();
    ship.checkEdges();
    
    if(isPressed)    ship.thrust();
    if(isRight)    ship.turn(-0.03);
    if(isLeft)    ship.turn(0.03);

    
}

//--------------------------------------------------------------
void testApp::draw(){
    ship.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'a' || key == 'A') isRight = true;
    if(key == 's' || key == 'S') isLeft = true;
    
    
        
    

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == 'a' || key == 'A') isRight = false;
    if(key == 's' || key == 'S') isLeft = false;
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    isPressed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    isPressed = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}