#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofSetVerticalSync(true);
    
    ofVec2f initPos(0, ofGetHeight()/2);
  
    vehicles.resize(100);
    
    for(unsigned int i = 0; i < vehicles.size(); i++){
        ofVec2f location(ofGetWidth(), ofGetHeight());

        vehicles[i].setup(location, ofRandom(2,4), 0.3);
    }
    
    newPath();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(unsigned int i = 0; i < vehicles.size(); i++){
        
        vehicles[i].applyBehaviours(vehicles, path);
        vehicles[i].update();
        vehicles[i].borders();
   
    }
    
  
}

//--------------------------------------------------------------
void ofApp::draw(){
    path.draw();

    for(unsigned int i = 0; i < vehicles.size(); i++){
        
        vehicles[i].draw();
        
    }
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
void ofApp::newVehicle(float x, float y){
    float topspeed = ofRandom(2,4);
    float maxforce = 0.3;
    ofVec2f location(x,y);
    Vehicle v;
    
    v.setup(location, topspeed, maxforce);
    vehicles.push_back(v);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        
         newPath();

       // for(unsigned int i = 0; i < vehicles.size(); i++){
            
      //      vehicles[i].debug = !vehicles[i].debug;
            
      //  }
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
    newVehicle(x, y);


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