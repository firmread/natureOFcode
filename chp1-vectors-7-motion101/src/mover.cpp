#include "mover.h"

mover::mover(){
    location.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    velocity.set(ofRandom(-2,2), ofRandom(-2,2));
}

void mover::update(){
    location += velocity;
}

void mover::display(){

    ofSetColor(127);
    ofDrawCircle(location.x, location.y, 24);

}

void mover::checkEdges(){
    if (location.x > ofGetWidth()) {
        location.x = 0;
    }
    else if (location.x < 0){
        location.x = ofGetWidth();
    }
    
    if (location.y > ofGetHeight()) {
        location.y = 0;
    }
    else if(location.y < 0){
        location.y = ofGetHeight();
    }
    
    
}