#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    
    ofVec2f initPos(0, ofGetHeight()/2);
    car1.setup(initPos, 3, 0.1);
    car2.setup(initPos, 5, 0.2);
    
    newPath();
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    car1.follow(path);
    car2.follow(path);
    
    car1.update();
    car2.update();
    
    car1.borders();
    car2.borders();
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    path.draw();

    car1.draw();
    car2.draw();
}


//--------------------------------------------------------------
void testApp::newPath(){
    path.setup();
    path.addPoint(0, ofGetHeight()/2);
    path.addPoint(ofRandom(0, ofGetWidth()/2), ofRandom(0, ofGetHeight()));
    path.addPoint(ofRandom(ofGetWidth()/2, ofGetWidth()), ofRandom(0, ofGetHeight()));
    path.addPoint(ofGetWidth(), ofGetHeight()/2);
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == ' '){
        car1.debug = !car1.debug;
        car2.debug = !car2.debug;
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
    ofBackground(255);
    newPath();


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