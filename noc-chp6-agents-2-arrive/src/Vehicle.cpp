//
//  Vehicle.cpp
//  NOC_6_1_Seek_trail
//
//  Created by Maria Paula Saba on 3/17/13.
//
//

#include "Vehicle.h"


void Vehicle::setup(int x, int y){
    
    location.set(0, 0);
    velocity.set(0, 0);
    acceleration.set(x, y);
    
    r = 6;
    maxForce = 0.1;
    topSpeed = 2;
    

}




void Vehicle::applyForce(const ofVec2f & force){
    ofVec2f f(force);
    acceleration += f;
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
    if(history.size() > 20){
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

    
    
}



