// learn more about C++ std::vector at
// http://en.cppreference.com/w/cpp/container/vector

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    particle* p = new particle(ofPoint(ofGetWidth()/2, 50));
    particles.push_back(p);
    
    for (int i = 0; i < particles.size(); i++){
        particles[i]->update();
        if(particles[i]->isDead()){
            particles.erase(particles.begin() + i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (auto& p: particles){
        p->display();
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
