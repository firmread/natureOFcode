#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofBackground(0);
    
//    increment = 0.01;
//    zincrement = 0.02;
    zoff = 0.0;
    
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    increment = ofMap(mouseX, 0, ofGetWidth(), 0.005, 0.1, true);
    zincrement = ofMap(mouseY, 0, ofGetHeight(), 0.005, 0.1, true);
    
    ofPixels pixels = img.getPixels();
    
    float xoff = 0.0;
    for(int x = 0; x < ofGetWidth(); x++) {
        xoff += increment;
        
        float yoff = 0.0;
        for(int y = 0; y < ofGetHeight(); y++) {
            yoff += increment;
            
            float bright = ofNoise(xoff, yoff, zoff)*255;
            pixels.setColor(x, y, ofColor(bright));
        }
    }
    
    img.setFromPixels(pixels);
    zoff += zincrement;
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0,0);
    ofDrawBitmapStringHighlight("increment = " + ofToString(increment)
                                +"\nzincrement = " + ofToString(zincrement)
                                , 10, 20);
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