#include "mover.h"

mover::mover(){
    location.set(ofRandomWidth(), ofRandomHeight());
    velocity.set(0, 0);
    topSpeed = 6;
    size = (int) ofRandom(6,12);
    cor = ofRandom(255);
}

void mover::setTarget(const ofPoint & target, float diff){
    acceleration = target - location;
    acceleration.normalize();
    acceleration *= diff;
}

void mover::update(){
    velocity += acceleration;
    velocity.limit(topSpeed);
    location += velocity;
}

void mover::draw(){
    ofSetColor(cor, 125);
    float angle = ofRadToDeg(atan2(velocity.y,velocity.x)) + 90;
    
    ofPushMatrix();
        ofTranslate(location.x, location.y);
        ofRotate(angle);
        ofDrawTriangle(-size+5, size, size-5, size, 0, -size);
    ofPopMatrix();

}

void mover::checkEdges(){
    
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
