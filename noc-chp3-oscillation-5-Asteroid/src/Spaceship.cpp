//
//  Spaceship.cpp
//  NOC_3_5_Asteroid
//
//  Created by Maria Paula Saba dos Reis on 2/13/13.
//
//

#include "Spaceship.h"


void Spaceship::setup(){
    location.set(ofGetWidth()/2, ofGetHeight()/2);
    velocity.set(0, 0);
    acceleration.set(0, 0);
    
    
    mass = 1;
    radius = mass*16;
    damping = 0.995;
    topSpeed = 6;
    heading = 0;

    thrusting = false;

}


void Spaceship::update(){
    
    velocity += acceleration;
    velocity *= damping;
    location += velocity;
    acceleration *= 0;

}


void Spaceship::draw(){
  
    
    ofPushMatrix();
    ofTranslate(location.x,location.y+radius);
    
    
    ofRotate(ofRadToDeg(heading));
 
    
    if (thrusting) ofSetColor(255,0,0);
    else ofSetColor(125);
    ofFill();
    
    
    // Booster rockets
    ofRect(-radius/2-2,radius,radius/2,radius/2);
    ofRect(-radius/2+10,radius,radius/2,radius/2);
    
    // A triangle
    ofBeginShape();
    ofVertex(-radius,radius);
    ofVertex(0,-radius);
    ofVertex(radius,radius);
    ofEndShape();
    
    ofPopMatrix();
    
 
   thrusting = false;



}

void Spaceship::thrust(){
    
    float angle = heading - PI/2;
    
    
    ofVec2f force(cos(angle), sin(angle));
    force*= 0.1;
    
    
    applyForce(force);
    thrusting = true;



}



void Spaceship::turn(float a){
    heading += a;
}


void Spaceship::checkEdges(){
    float buffer = radius*2;
    if (location.x > ofGetWidth() +  buffer) location.x = -buffer;
    else if (location.x <    -buffer) location.x = ofGetWidth()+buffer;
    if (location.y > ofGetHeight() + buffer) location.y = -buffer;
    else if (location.y <    -buffer) location.y = ofGetHeight()+buffer;


}


void Spaceship::applyForce(const ofVec2f & force){
    
    ofVec2f f(force);
    acceleration += f;
}




