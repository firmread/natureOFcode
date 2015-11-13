//
//  Vehicle.cpp
//  NOC_6_1_Seek_trail
//
//  Created by Maria Paula Saba on 3/17/13.
//
//

#include "Vehicle.h"


void Vehicle::setup(ofVec2f & l, float ts, float mf){
    acceleration.set(0, 0);
    velocity.set(0.0, 0.0);
    location = l;
    
    r = 4;
    maxForce = mf;
    topSpeed =ts;    

}




void Vehicle::applyForce(const ofVec2f & force){
    ofVec2f f(force);
    acceleration += f;
}



void Vehicle::borders(){

    if (location.x < -r) location.x = ofGetWidth()+r;
    if (location.y < -r) location.y = ofGetHeight()+r;
    if (location.x > ofGetWidth()+r) location.x = -r;
    if (location.y > ofGetHeight()+r) location.y = -r;

}


void Vehicle::follow(const Flowfield & flow){

    // What is the vector at that spot in the flow field?
    ofVec2f desired = flow.lookup(location);
    // Scale it up by maxspeed
    desired *= topSpeed;
    // Steering is desired minus velocity
    ofVec2f steer = desired - velocity;
    steer.limit(maxForce);  // Limit to maximum steering force
    applyForce(steer);

    
    
}



void Vehicle::update(){
    velocity += acceleration;
    location += velocity;
    velocity.limit(topSpeed);
    acceleration *= 0;
    
//    history.push_back(location);
//    if(history.size() > 20){
//        history.erase(history.begin());
//    }
    
    
}

void Vehicle::draw(){
    
    ofSetColor(175);
    ofNoFill();
    
//    ofBeginShape();
//    for(int i = 0; i < history.size(); i++){
//        ofVertex(history[i].x, history[i].y);
//    }
//    ofEndShape();
    
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



