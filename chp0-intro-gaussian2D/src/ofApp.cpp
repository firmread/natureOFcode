#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //create an alpha blended background
    ofSetColor(0, 2);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //get 3 gaussian random numbers w/ mean of 0 and standard deviation of 1.0
    float r = gaussian();
    float g = gaussian();
    float b = gaussian();
    
    //define standard deviation and mean
    float sd = 100;
    float mean = 100;
    
    //scale by standard deviation and mean
    //also constrain to between (0,255) since we are dealing with color
    r = ofClamp((r * sd) + mean,0,255);
    
    //repeat for g & b
    sd = 20;
    mean = 200;
    g = ofClamp((g * sd) + mean,0,255);
    sd = 50;
    mean = 150;
    b = ofClamp((b * sd) + mean,0,255);
    
    //get more gaussian numbers, this time for location
    float xloc = gaussian();
    float yloc = gaussian();
    sd = ofGetWidth()/10;
    mean = ofGetWidth()/2;
    xloc = ( xloc * sd ) + mean;
    yloc = ( yloc * sd ) + mean;

    ofSetColor(r, g, b);
    ofDrawCircle(xloc, yloc, 8);
}


// algorithm from ofxGaussian http://github.com/andyr0id/ofxGaussian

float ofApp::gaussian(){
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        
        return v1 * multiplier;
    }
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