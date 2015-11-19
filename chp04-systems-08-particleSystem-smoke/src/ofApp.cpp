#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    img.load("texture.png");
    ps = new particleSystem(ofPoint(ofGetWidth()/2, ofGetHeight()-75), img);
}

//--------------------------------------------------------------
void ofApp::update(){
    ps->addParticle();
    
    // Calculate a "wind" force based on mouse horizontal position
    float dx = ofMap(mouseX,0,ofGetWidth(),-0.2,0.2);
    wind = *new ofPoint(dx,0);
    ps->applyForce(wind);
    
    ps->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ps->display();
    drawVector(wind, *new ofPoint(ofGetWidth()/2,50), 500);
}

//--------------------------------------------------------------

void ofApp::drawVector(ofPoint v, ofPoint loc, float scayl){
    ofPushMatrix();
        float arrowsize = 4;
        // Translate to location to render vector
        ofTranslate(loc);
        ofColor(255);
        // Call vector heading function to get direction (note that pointing up is a heading of 0) and rotate
        float angle = (float)atan2(-v.y, v.x);
        float theta =  -1.0*angle;
        float heading2D = ofRadToDeg(theta);
        
        ofRotateZ(heading2D);
        
        // Calculate length of vector & scale it to be bigger or smaller if necessary
        float len = v.length()*scayl;
        // Draw three lines to make an arrow (draw pointing up since we've rotate to the proper direction)
        ofDrawLine(0,0,len,0);
        ofDrawLine(len,0,len-arrowsize,+arrowsize/2);
        ofDrawLine(len,0,len-arrowsize,-arrowsize/2);
    ofPopMatrix();
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
