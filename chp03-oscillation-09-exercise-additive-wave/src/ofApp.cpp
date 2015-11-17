// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// NOC_3_09 Additive Wave
// Create a more complex wave by adding two waves together.

// Maybe better for this answer to be OOP???


#include "ofApp.h"

void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableSmoothing();

    maxwaves = 5;
    xspacing = 8;
    w = ofGetWidth() + 16;
    
    for (int i = 0; i < maxwaves; i++) {
        
        float a = ofRandom(10,30);
        amplitude.push_back(a);
        
        float period = ofRandom(100,300); // How many pixels before the wave repeats
        float d = (TWO_PI / period) * xspacing;
        dx.push_back(d);
        
    }

    for (int i=0;i<w/xspacing;i++) {
        yvalues.push_back(0.0);
    }
    

    
}

void ofApp::update(){
    calcWave();
}


void ofApp::draw(){
    renderWave();

}

void ofApp::calcWave() {
    // Increment theta (try different values for 'angular velocity' here
    theta += 0.02;
    
    // Set all height values to zero
    for (int i = 0; i < yvalues.size(); i++) {
        yvalues[i] = 0;
    }
    
    // Accumulate wave height values
    for (int j = 0; j < maxwaves; j++) {
        float x = theta;
        for (int i = 0; i < yvalues.size(); i++) {
            // Every other wave is cosine instead of sine
            if (j % 2 == 0)  yvalues[i] += sin(x) * amplitude[j];
            else yvalues[i] += cos(x)*amplitude[j];
            x += dx[j];
        }
    }
}

void ofApp::renderWave() {
    ofSetColor(255,70);
    for (int i = 0; i < yvalues.size(); i++) {
        ofDrawCircle(i * xspacing, ofGetHeight()/2 + yvalues[i], 8);
    }
}

void ofApp::mouseMoved(int x, int y ){ }
void ofApp::keyPressed(int key){ }
void ofApp::keyReleased(int key){ }
void ofApp::mouseDragged(int x, int y, int button){ }
void ofApp::mousePressed(int x, int y, int button){ }
void ofApp::mouseReleased(int x, int y, int button){ }
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }