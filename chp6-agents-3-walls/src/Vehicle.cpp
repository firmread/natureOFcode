//
//  Vehicle.cpp
//  NOC_6_1_Seek_trail
//
//  Created by Maria Paula Saba on 3/17/13.
//
//

#include "Vehicle.h"


void Vehicle::setup(int x, int y){
    
    acceleration.set(0, 0);
    velocity.set(0.4, 0.6);
    location.set(x, y);
    
    r = 6;
    maxForce = 0.1;
    topSpeed = 4;
    d = 60;
    

}




void Vehicle::applyForce(const ofVec2f & force){
    ofVec2f f(force);
    acceleration += f;
}


void Vehicle::boundaries(){

    ofVec2f desired(0,0);
    ofVec2f null(0,0);
    
    
    
    
    if (location.x < d) {
        desired.set(topSpeed, velocity.y);
    }
    else if (location.x > ofGetWidth() -d) {
        desired.set(-topSpeed, velocity.y);
    }
    
    if (location.y < d) {
        desired.set(velocity.x, topSpeed);
    }
    else if (location.y > ofGetHeight()-d) {
        desired.set(velocity.x, -topSpeed);
    }
    
    if (desired != null ) {
        desired.normalize();
        desired*= topSpeed;
        ofVec2f steer = desired - velocity;
        steer.limit(maxForce);
        applyForce(steer);
    }


    predict = velocity;
    predict.normalize();
    predict *= 60;
    
    
    futureLocation = location + predict;



}

void Vehicle::circleBoundaries(float cR, ofVec2f cL){

    circleLocation = cL;
    radius = cR;

    
    ofVec2f desired(0,0);
    ofVec2f null(0,0);
    
    
    predict = velocity;
    predict.normalize();
    predict *= 60;
    
    
    futureLocation = location + predict;
    
    
    float distance = ofDist(futureLocation.x, futureLocation.y, circleLocation.x, circleLocation.y);
 
    
    if (distance > radius) {
        ofVec2f toCenter = circleLocation - location;
        toCenter.normalize();
        toCenter*= velocity.length();
        
        desired = velocity + toCenter;
        desired.normalize();
        desired*= topSpeed;
    }
    
    
    if (desired != null ) {
        desired.normalize();
        desired*= topSpeed;
        ofVec2f steer = desired - velocity;
        steer.limit(maxForce);
        applyForce(steer);
    }
    
    

    
    
}

void Vehicle::seek(const ofVec2f & target){
    ofVec2f desired;
    desired = target - location;
    
    desired.normalize();
    desired*=topSpeed;
    
    ofVec2f steer;
    steer = desired - velocity;
    steer.limit(maxForce);
    
    applyForce(steer);
    
    
}

void Vehicle::arrive(const ofVec2f & target){
    ofVec2f desired;
    desired = target - location;
    
    float d = desired.length();
    
    if (d < 100) {
        float m = ofMap(d,0,100,0,topSpeed);
        desired*=m;
        
    } else {
        desired*=topSpeed;
    }



    ofVec2f steer;
    steer = desired - velocity;
    steer.limit(maxForce);
    
    applyForce(steer);

}


void Vehicle::update(){
    velocity += acceleration;
    location += velocity;
    velocity.limit(topSpeed);
    acceleration *= 0;
    
    history.push_back(location);
    if(history.size() > 100){
        history.erase(history.begin());
    }
    
    
}

void Vehicle::draw(){
    
    ofSetColor(0);
    ofNoFill();
    
    ofBeginShape();
    for(int i = 0; i < history.size(); i++){
        ofVertex(history[i].x, history[i].y);
    }
    ofEndShape();
    
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

    
    ofSetColor(255, 0, 0);
    ofFill();
    ofEllipse(futureLocation,4,4);
    
}



