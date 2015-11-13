#include "testApp.h"

/*
 Openframewoks doesn't include a gaussian random generator. This example assumes that ofxGausisan is
 installed. You can get it at http://github.com/andryr0id/ofxGaussian
 */

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(30);
    ofSetBackgroundColor(0);
    //Disable backgroud clean each frame
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    //create an alpha blended background
    ofSetColor(0, 2);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    //get 3 gaussian random numbers w/ mean of 0 and standard deviation of 1.0
    float r = ofxGaussian();
    float g = ofxGaussian();
    float b = ofxGaussian();
    
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
    mean = 0;
    b = ofClamp((b * sd) + mean,0,255);
    
    //get more gaussian numbers, this time for location
    float xloc = ofxGaussian();
    float yloc = ofxGaussian();
    sd = ofGetWidth()/10;
    mean = ofGetWidth()/2;
    xloc = ( xloc * sd ) + mean;
    yloc = ( yloc * sd ) + mean;

    ofSetColor(r, g, b);
    ofCircle(xloc, yloc, 8);
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