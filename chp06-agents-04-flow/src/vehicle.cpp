#include "vehicle.h"

vehicle::vehicle(ofPoint & l, float ts, float mf){
    acceleration.set(0, 0);
    velocity.set(0.0, 0.0);
    location = l;
    
    r = 4;
    maxForce = mf;
    maxSpeed =ts;    

}




void vehicle::applyForce(const ofPoint & force){
    ofPoint f(force);
    acceleration += f;
}



void vehicle::borders(){

    if (location.x < -r) location.x = ofGetWidth()+r;
    if (location.y < -r) location.y = ofGetHeight()+r;
    if (location.x > ofGetWidth()+r) location.x = -r;
    if (location.y > ofGetHeight()+r) location.y = -r;

}


void vehicle::follow(const flowField & flow){

    // What is the vector at that spot in the flow field?
    ofPoint desired = flow.lookup(location);
    // Scale it up by maxspeed
    desired *= maxSpeed;
    // Steering is desired minus velocity
    ofPoint steer = desired - velocity;
    steer.limit(maxForce);  // Limit to maximum steering force
    applyForce(steer);

    
    
}



void vehicle::update(){
    velocity += acceleration;
    location += velocity;
    velocity.limit(maxSpeed);
    acceleration *= 0;
    
}

void vehicle::draw(){
    
    ofSetColor(175);
    float angle = ofRadToDeg(atan2(velocity.y,velocity.x)) + 90;
    ofFill();
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotate(angle);
    
    ofBeginShape();
    ofVertex(0, -r*2);
    ofVertex(-r, r*2);
    ofVertex(r, r*2);
    ofEndShape();
    ofPopMatrix();

    
}



