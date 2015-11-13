#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
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
void testApp::update(){
    for(unsigned int i = 0; i < vehicles.size(); i++){
        
        vehicles[i].applyBehaviours(vehicles, path);
        vehicles[i].update();
        vehicles[i].borders();
   
    }
    
  
}

//--------------------------------------------------------------
void testApp::draw(){
    path.draw();

    for(unsigned int i = 0; i < vehicles.size(); i++){
        
        vehicles[i].draw();
        
    }
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
void testApp::newVehicle(float x, float y){
    float topspeed = ofRandom(2,4);
    float maxforce = 0.3;
    ofVec2f location(x,y);
    Vehicle v;
    
    v.setup(location, topspeed, maxforce);
    vehicles.push_back(v);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == ' '){
        
         newPath();

       // for(unsigned int i = 0; i < vehicles.size(); i++){
            
      //      vehicles[i].debug = !vehicles[i].debug;
            
      //  }
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
    newVehicle(x, y);


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