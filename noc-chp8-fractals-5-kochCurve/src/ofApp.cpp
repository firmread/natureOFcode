#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(true);
    ofVec2f st = ofVec2f(ofGetWidth() / 3,ofGetHeight()/3);
    ofVec2f ed = ofVec2f(2 * ofGetWidth() / 3,ofGetHeight()/3);
    // kc = KochCurve(st,ed,5);

    pp = PolygonPoints(6,ofVec2f(ofGetWidth() / 2 ,ofGetHeight()/2),300.0);
    pp2 = PolygonPoints(3,ofVec2f(ofGetWidth() / 2,ofGetHeight()/2),420);

    vector<ofVec2f> hexPoints = pp.getPoints();
    for(int i= 0; i < hexPoints.size(); i++){
        int nextPointPos = (i<hexPoints.size()-1)?i+1:0;
        kc.push_back(KochCurve(hexPoints[i],hexPoints[nextPointPos],5));
    }

    hexPoints = pp2.getPoints();
    for(int i= 0; i < hexPoints.size(); i++){
        int nextPointPos = (i<hexPoints.size()-1)?i+1:0;
        kc2.push_back(KochCurve(hexPoints[nextPointPos],hexPoints[i],5)); // reversing order of points reverses direction of K. Curve (in / out)
    }


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i= 0; i < kc.size(); i++){
        kc[i].display();
    }
    for(int i= 0; i < kc2.size(); i++){
        kc2[i].display();
    }

    pp2.display(true,false);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
