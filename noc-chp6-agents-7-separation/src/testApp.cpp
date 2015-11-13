#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
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
void testApp::update(){
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].separate(vehicles);
        vehicles[i].borders();
        vehicles[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].draw();
    }
    cout << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
   
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
 
    Vehicle v;
    v.setup(mouseX, mouseY);
    vehicles.push_back(v);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

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