#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    ofBackground(ofColor::beige);
    
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.setFPS(60.0);
    
    
    //with ofxBox2d, any body with (density == 0.f) is assigned as static body
    
    boundaries.push_back(shared_ptr<ofxBox2dRect>(new ofxBox2dRect));
    boundaries.back().get()->setup(box2d.getWorld(), ofGetWidth()/4, ofGetHeight()-5, ofGetWidth()/2-50, 10);
    boundaries.back().get()->setDensity(0.0);
    
    boundaries.push_back(shared_ptr<ofxBox2dRect>(new ofxBox2dRect));
    boundaries.back().get()->setup(box2d.getWorld(), 3*ofGetWidth()/4,ofGetHeight()-50, ofGetWidth()/2-50, 10);
    boundaries.back().get()->setDensity(0.0);
    
}

//--------------------------------------------------------------
void ofApp::update() {
    box2d.update();
    
    float w = ofRandom(4,16);
    float h = ofRandom(4,16);
    boxes.push_back(shared_ptr<ofxBox2dRect>(new ofxBox2dRect));
    boxes.back().get()->setPhysics(1.0, 0.5, 0.3);
//    setPhysics(density, bounce, friction)
    boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
    
    // some of the value has helper functions at ofxBox2d level
    boxes.back().get()->setVelocity(ofRandom(-5,5), ofRandom(2,5));
    // some doesn't, but you can still access box2d lib directly!
    boxes.back().get()->body->SetAngularVelocity(ofRandom(-5, 5));
    
    // remove shapes offscreen
    ofRemove(boxes, ofxBox2dBaseShape::shouldRemoveOffScreen);
    cout << "boxes amount: " << boxes.size() << endl;
}


//--------------------------------------------------------------
void ofApp::draw() {
    
    for(auto & b : boxes) {
        ofSetHexColor(0xBF2545);
        b->draw();
    }
    
    for(auto & bound : boundaries){
        ofSetColor(ofColor::cornflowerBlue);
        bound->draw();
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

