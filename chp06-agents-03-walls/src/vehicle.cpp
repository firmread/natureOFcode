#include "vehicle.h"

void vehicle::setup(int x, int y){
    acceleration.set(0, 0);
    velocity.set(0.4, 0.6);
    location.set(x, y);
    
    r = 6;
    maxForce = 0.1;
    maxSpeed = 4;
    d = 60;

}

void vehicle::applyForce(const ofPoint & force){
    acceleration += force;
}


void vehicle::boundaries(){

    ofPoint desired(0,0);
    ofPoint null(0,0);
    
    if (location.x < d) {
        desired.set(maxSpeed, velocity.y);
    }
    else if (location.x > ofGetWidth() -d) {
        desired.set(-maxSpeed, velocity.y);
    }
    
    if (location.y < d) {
        desired.set(velocity.x, maxSpeed);
    }
    else if (location.y > ofGetHeight()-d) {
        desired.set(velocity.x, -maxSpeed);
    }
    
    if (desired != null ) {
        desired.normalize();
        desired*= maxSpeed;
        ofPoint steer = desired - velocity;
        steer.limit(maxForce);
        applyForce(steer);
    }

    predict = velocity;
    predict.normalize();
    predict *= 60;
    
    futureLocation = location + predict;
}

void vehicle::circleBoundaries(float cR, ofPoint cL){

    circleLocation = cL;
    radius = cR;

    ofPoint desired(0,0);
    ofPoint null(0,0);
    
    predict = velocity;
    predict.normalize();
    predict *= 60;
    
    futureLocation = location + predict;
    
    float distance = ofDist(futureLocation.x, futureLocation.y, circleLocation.x, circleLocation.y);
    
    if (distance > radius) {
        ofPoint toCenter = circleLocation - location;
        toCenter.normalize();
        toCenter*= velocity.length();
        
        desired = velocity + toCenter;
        desired.normalize();
        desired*= maxSpeed;
    }
    
    if (desired != null ) {
        desired.normalize();
        desired*= maxSpeed;
        ofPoint steer = desired - velocity;
        steer.limit(maxForce);
        applyForce(steer);
    }
    
}

void vehicle::seek(const ofPoint & target){
    ofPoint desired = target - location;
    
    desired.normalize();
    desired*=maxSpeed;
    
    ofPoint steer = desired - velocity;
    steer.limit(maxForce);
    
    applyForce(steer);
}

void vehicle::arrive(const ofPoint & target){
    ofPoint desired = target - location;
    float d = desired.length();
    
    if (d < 100) {
        float m = ofMap(d,0,100,0,maxSpeed);
        desired*=m;
        
    } else {
        desired*=maxSpeed;
    }

    ofPoint steer = desired - velocity;
    steer.limit(maxForce);
    
    applyForce(steer);

}


void vehicle::update(){
    velocity += acceleration;
    location += velocity;
    velocity.limit(maxSpeed);
    acceleration *= 0;
    
    history.push_back(location);
    if(history.size() > 100){
        history.erase(history.begin());
    }
}

void vehicle::draw(){
    
    ofSetColor(0);
    for(int i = 1; i < history.size(); i++){
        ofDrawLine(history[i-1].x, history[i-1].y, history[i].x, history[i].y);
    }
    
    float angle = ofRadToDeg(atan2(velocity.y,velocity.x)) + 90;
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
    ofDrawCircle(futureLocation,4);
    
}

