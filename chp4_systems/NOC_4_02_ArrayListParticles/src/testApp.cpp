#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
}

//--------------------------------------------------------------
void testApp::update(){
    parray.push_back(new Particle(ofPoint(ofGetWidth()/2, 50)));
    
    for (int i = 0; i < parray.size(); i++){
        parray.at(i)->update();
        if(parray.at(i)->isDead()){
            cout << "Particle dead!" << endl;
            parray.erase(parray.begin() + i);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){    
    for (int i = 0; i < parray.size(); i++){
        parray.at(i)->display();
    }
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