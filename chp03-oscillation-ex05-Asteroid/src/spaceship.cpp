#include "spaceship.h"
void spaceship::setup(){
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

void spaceship::update(){
    
    velocity += acceleration;
    velocity *= damping;
    location += velocity;
    acceleration *= 0;

}

void spaceship::draw(){
  
    ofPushMatrix();
        ofTranslate(location.x,location.y+radius);
        ofRotate(ofRadToDeg(heading));
     
        if (thrusting) ofSetColor(ofColor::salmon);
        else ofSetColor(125);
    
        // Booster rockets
        ofDrawRectangle(-radius/2-2,radius,radius/2,radius/2);
        ofDrawRectangle(-radius/2+10,radius,radius/2,radius/2);
        
        // A triangle
        ofBeginShape();
            ofVertex(-radius,radius);
            ofVertex(0,-radius);
            ofVertex(radius,radius);
        ofEndShape();
    ofPopMatrix();
    thrusting = false;
}

void spaceship::thrust(){
    
    float angle = heading - PI/2;
    
    ofPoint force(cos(angle), sin(angle));
    force*= 0.1;
    
    applyForce(force);
    thrusting = true;
}

void spaceship::turn(float a){
    heading += a;
}


void spaceship::checkEdges(){
    float buffer = radius*2;
    if (location.x > ofGetWidth() +  buffer) location.x = -buffer;
    else if (location.x < buffer) location.x = ofGetWidth()+buffer;
    
    if (location.y > ofGetHeight() + buffer) location.y = -buffer;
    else if (location.y < -buffer) location.y = ofGetHeight()+buffer;
}


void spaceship::applyForce(const ofPoint & force){
    ofPoint f(force);
    acceleration += f;
}




