#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundColor(m_backgroundColor);
  ofSetBackgroundAuto(false);
  ofSetCircleResolution(100);

  auto position = glm::vec2 { ofGetWidth() / 2, ofGetHeight() / 2 };

  m_walker.setup(position, 2);
}

//--------------------------------------------------------------
void ofApp::update(){
  m_walker.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofFill();
  ofSetColor(m_walkerColor);

  m_walker.draw();
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
