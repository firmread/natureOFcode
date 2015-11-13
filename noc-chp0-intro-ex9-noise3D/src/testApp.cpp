#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(30);
    ofBackground(0);
    
    increment = 0.01;
    // The noise function's 3rd argument, a global variable that increments once per cycle
    zoff = 0.0;
    // We will increment zoff differently than xoff and yoff
    zincrement = 0.02;
    
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
}

//--------------------------------------------------------------
void testApp::update(){
    ofPixels pixels = img.getPixelsRef();
    
    float xoff = 0.0;
    
    // For every x,y coordinate in a 2D space, calculate a noise value and produce a brightness value
    for(int x = 0; x < ofGetWidth(); x++) {
        xoff += increment; // Increment xoff 
        float yoff = 0.0; // For every xoff, start yoff at 0
        for(int y = 0; y < ofGetHeight(); y++) {
            yoff += increment; // Increment yoff
             // Calculate noise and scale by 255
            float bright = ofNoise(xoff, yoff, zoff)*255;
            pixels.setColor(x, y, ofColor(bright));
            
        }
    }
    
    img.setFromPixels(pixels);
    zoff += zincrement;
}

//--------------------------------------------------------------
void testApp::draw(){
    img.draw(0,0);
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