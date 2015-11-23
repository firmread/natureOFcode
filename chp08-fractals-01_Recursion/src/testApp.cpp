#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground( 0 );
    ofSetColor( 255 );
    
    
}

void testApp::drawDiamond(float x, float y, float size ){
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    if( size > 16 ){
        drawDiamond( x + size/2, y, size/2 );
        drawDiamond( x - size/2, y, size/2 );
        
        drawDiamond( x, y + size/2, size/2 );
        drawDiamond( x, y - size/2, size/2 );
    }
    
    ofPushMatrix();{
        ofTranslate( x, y);
        ofRotate( 45 );
        ofRect( 0, 0, size, size );
    }ofPopMatrix();
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofNoFill();
    drawDiamond( ofGetWindowWidth()/2, ofGetWindowHeight()/2, ofGetWindowWidth()/2 );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
