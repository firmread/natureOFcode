#include "ofApp.h"

void ofApp::setup() {
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.setFPS(60.0);
}

//--------------------------------------------------------------
void ofApp::update() {
    box2d.update();
    
    float w = ofRandom(10, 20);
    float h = ofRandom(10, 20);
    boxes.push_back(shared_ptr<ofxBox2dRect>(new ofxBox2dRect));
    boxes.back().get()->setPhysics(3.0, 0.53, 0.1);
    boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
    
    // remove shapes offscreen
    ofRemove(boxes, ofxBox2dBaseShape::shouldRemoveOffScreen);
    cout << boxes.size() << endl;
}


//--------------------------------------------------------------
void ofApp::draw() {
    
    for(auto & b : boxes) {
        ofSetHexColor(0xBF2545);
        b->draw();
    }

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) { }
//--------------------------------------------------------------
void ofApp::keyReleased(int key) { }
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) { }
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) { }
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) { }
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) { }
//--------------------------------------------------------------
void ofApp::resized(int w, int h){ }

