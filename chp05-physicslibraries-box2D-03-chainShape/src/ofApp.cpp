#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);
    ofBackground(ofColor::beige);
    
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.setFPS(60.0);
    
    
    surface.addVertex(0, ofGetHeight()/2);
    surface.addVertex(ofGetWidth()/2, ofGetHeight()/2+50);
    surface.addVertex(ofGetWidth(), ofGetHeight()/2);
    
    surface.setPhysics(0.0, 0.5, 0.5);
    surface.create(box2d.getWorld());
    
    surface.mesh.addVertex(ofPoint(ofGetWidth(), 0));
    surface.mesh.addVertex(ofPoint(0,0));
    
}

//--------------------------------------------------------------
void ofApp::update() {
    box2d.update();
    
    if (ofGetMousePressed()){
        float r = ofRandom(4,8);
        particles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
        particles.back().get()->setPhysics(1.0, 0.3, 0.01);
    //    setPhysics(density, bounce, friction)
        particles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r);
        
        particles.back().get()->setVelocity(ofRandom(-10.f,10.f), ofRandom(5.f,10.f));
        particles.back().get()->body->SetAngularVelocity(ofRandom(-10, 10));
    }
    
    // remove shapes offscreen
    ofRemove(particles, ofxBox2dBaseShape::shouldRemoveOffScreen);
    cout << "boxes amount: " << particles.size() << endl;
}


//--------------------------------------------------------------
void ofApp::draw() {
    
    ofSetColor(ofColor::azure);
    surface.draw();
    
    for(auto & p : particles) {
        ofSetHexColor(0xBF2545);
        p->draw();
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

