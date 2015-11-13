//
//  Mover.cpp
//  NOC_3_3_pointingDirection
//
//  Created by Maria Paula Saba dos Reis on 2/13/13.
//
//

#include "Mover.h"

void Mover::setup(){
    location.set(ofRandomWidth(), ofRandomHeight());
    velocity.set(0, 0);
    topSpeed = 6;
    size = (int) ofRandom(6,12);
    cor = ofRandom(255);
}

void Mover::setTarget(const ofVec2f & target, float diff){
    acceleration = target - location;
    acceleration.normalize();
    acceleration *= diff;
}

void Mover::update(){
    // acceleration towards the mouse is set in testApp::setTarget
    velocity += acceleration;
    velocity.limit(topSpeed);
    location += velocity;
}


void Mover::draw(){
    ofSetColor(cor, 125);
    
    float angle = ofRadToDeg(atan2(velocity.y,velocity.x)) + 90;
    
    ofPushMatrix();
    
    ofTranslate(location.x, location.y);
    ofRotate(angle);
    
    ofTriangle(-size+5, size, size-5, size, 0, -size);
    //ofEllipse(location, size, size);    
    ofPopMatrix();
    
    
    cout << angle << endl;

    
}



void Mover::checkEdges(){
    
    if (location.x > ofGetWidth()){
        location.x = 0;
    } else if (location.x < 0){
        location.x = ofGetWidth();
    }
    
    if (location.y > ofGetHeight()){
        location.y = 0;
    } else if (location.y < 0){
        location.y = ofGetHeight();
    }
    
}
