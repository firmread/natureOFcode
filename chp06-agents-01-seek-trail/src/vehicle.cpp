#include "vehicle.h"


void vehicle::setup(int x, int y){
    
    location.set(0, 0);
    velocity.set(0, -2);
    acceleration.set(x, y);
    
    r = 6;
    maxForce = 0.1;
    maxSpeed = 4;

}

void vehicle::applyForce(const ofPoint & force){
    acceleration += force;
}

void vehicle::seek(const ofPoint & target){
    ofPoint desired;
    desired = target - location;
    
    desired.normalize();
    desired*=maxSpeed;
    
    ofPoint steer;
    steer = desired - velocity;
    steer.limit(maxForce);
    
    applyForce(steer);
    
}

void vehicle::update(){
    velocity += acceleration;
    velocity.limit(maxSpeed);
    location += velocity;
    acceleration *= 0;
    
    history.push_back(location);
    if(history.size() > 100){
        history.erase(history.begin());
    }
    
}

void vehicle::draw(){
    
    ofSetColor(ofColor::fireBrick);
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

    
    
}



