// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// NOC_3_09 Additive Wave
// Create a more complex wave by adding two waves together.

// Maybe better for this answer to be OOP???


#include "testApp.h"

void testApp::setup(){

    ofSetFrameRate(30);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);

    maxwaves = 5;
    xspacing = 8;
    w = ofGetWidth() + 16;
    
    for (int i=0;i<maxwaves;i++) {
        amplitude.push_back(0.0);
        dx.push_back(0.0);
    }
    
    for (int i = 0; i < maxwaves; i++) {
        amplitude[i] = ofRandom(10,30);
        float period = ofRandom(100,300); // How many pixels before the wave repeats
        dx[i] = (TWO_PI / period) * xspacing;
    }
    
    for (int i=0;i<w/xspacing;i++) {
        yvalues.push_back(0.0);
    }
    
//    yvalues = new float[w/xspacing];

    
}

void testApp::update(){
    calcWave();
}


void testApp::draw(){

    ofBackground(0);
    renderWave();

}

void testApp::calcWave() {
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

void testApp::renderWave() {
    // A simple way to draw the wave with an ellipse at each location
//    noStroke();
    
    ofSetColor(255,50);
//    ellipseMode(CENTER);
    for (int i = 0; i < yvalues.size(); i++) {
        ofCircle(i * xspacing, ofGetHeight()/2 + yvalues[i], 16, 16);
    }
}


void testApp::mouseMoved(int x, int y ){

}

void testApp::keyPressed(int key){

}

void testApp::keyReleased(int key){

}

void testApp::mouseDragged(int x, int y, int button){

}

void testApp::mousePressed(int x, int y, int button){

}

void testApp::mouseReleased(int x, int y, int button){

}

void testApp::windowResized(int w, int h){

}

void testApp::gotMessage(ofMessage msg){

}

void testApp::dragEvent(ofDragInfo dragInfo){

}





