#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
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
void testApp::update(){
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].follow(flowfield);
        vehicles[i].update();
        vehicles[i].borders();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    if (isDebugMode){
        flowfield.draw();
    }
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].draw();
    }
  
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == ' ') {
        isDebugMode = !isDebugMode;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    flowfield.init();

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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