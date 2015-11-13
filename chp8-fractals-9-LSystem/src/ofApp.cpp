#include "ofApp.h"

int counter = 0;
bool bRender = false; // our noLoop equivalent

//--------------------------------------------------------------
void ofApp::setup(){
    /*
     // Create an empty ruleset
     Rule[] ruleset = new Rule[2];
     // Fill with two rules (These are rules for the Sierpinksi Gasket Triangle)
     ruleset[0] = new Rule('F',"F--F--F--G");
     ruleset[1] = new Rule('G',"GG");
     // Create LSystem with axiom and ruleset
     lsys = new LSystem("F--F--F",ruleset);
     turtle = new Turtle(lsys.getSentence(),width*2,TWO_PI/3);
     */
    
    /*Rule[] ruleset = new Rule[1];
     //ruleset[0] = new Rule('F',"F[F]-F+F[--F]+F-F");
     ruleset[0] = new Rule['F',"FF+[+F-F-F]-[-F+F+F]");
     lsys = new LSystem("F-F-F-F",ruleset);
     turtle = new Turtle(lsys.getSentence(),width-1,PI/2);
     */
    
    vector<Rule *> ruleset;
    ruleset.resize(1);
    ruleset[0] = new Rule('F', "FF+[+F-F-F]-[-F+F+F]");
    lsys = new LSystem("F", ruleset);
    turtle = new Turtle(lsys->getSentence(), ofGetHeight()/3, ofDegToRad(25));
    
    ofBackground(255);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if ( bRender ){
        ofBackground(255);
        ofSetColor(0);
        //text("Click mouse to generate", 10, height-10);
        
        ofTranslate(ofGetWidth()/2, ofGetHeight());
        ofRotateZ(-90);
        turtle->render();
        bRender = false;
    }
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
    if (counter < 5) {
        ofPushMatrix();
        lsys->generate();
        //println(lsys.getSentence());
        turtle->setToDo(lsys->getSentence());
        turtle->changeLen(0.5);
        ofPopMatrix();
        bRender = true;
        counter++;
    }
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
