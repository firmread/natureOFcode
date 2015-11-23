#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    // sierpinski
    vector<Rule> myRules;
    myRules.push_back( Rule('F',"F--F--F--G") );
    myRules.push_back( Rule('G',"GG") );
    
    system.setup("F--F--F", myRules);
    turtle.setup( 10, 60 );
    turtle.setInstructions( system.sentence );
    
    
    /*
    // boxes
    vector<Rule> myRules;
    myRules.push_back( Rule('F',"F[F]-F+F[--F]+F-F") );
    system.setup( "F-F-F-F", myRules );
    turtle.setup( 10, 90 );
    turtle.setInstructions( system.sentence );
    */
    
    /*
    // tree
    vector<Rule> myRules;
    myRules.push_back( Rule('F',"FF+[+F-F-F]-[-F+F+F]") );
    system.setup("F", myRules);
    turtle.setup( 10, 25 );
    turtle.setInstructions( system.sentence );
    */
    
    ofBackground( 0 );
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
        ofTranslate( 0, ofGetWindowHeight() );
//        ofRotate( -90 );
        turtle.draw();
    ofPopMatrix();
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
    system.addGeneration();
    turtle.setInstructions( system.sentence );
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
