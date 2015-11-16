#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofBackground(255);
    heights.resize(ofGetWidth());   //fills the vector with zero
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float e = 2.71828183;
    //"e", see http://mathforum.org/dr.math/faq/faq.e.html for more info
    float m = 0;
    //default mean of 0
    float sd = ofMap(mouseX, 0, ofGetWidth(), 0.4, 2);
    //standard deviation based on mouseX
    
    for (int i = 0; i < heights.size(); i++) {
        float xcoord = ofMap(i, 0, ofGetWidth(), -3, 3);
        float sq2pi = sqrt(2*PI);
        //square root of 2 * PI
        float xmsq = -1*(xcoord-m)*(xcoord-m);
        //-(x - mu)^2
        float sdsq = sd*sd;
        //variance (standard deviation squared)
        
        heights[i] = (1 / (sd * sq2pi)) * (pow(e, (xmsq/sdsq)));
        //P(x) function
    }
    
    ofSetColor(0);
    ofNoFill();
    
    ofBeginShape();
        for (int i = 0; i < heights.size()-1; i++) {
            float x = i;
            float y = ofMap(heights[i], 0, 1, ofGetHeight()-2, 2);
            ofVertex(x, y);
        }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
//--------------------------------------------------------------
void ofApp::keyReleased(int key){ }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){ }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){ }
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){ }
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){ }
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }