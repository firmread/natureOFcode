//
//  Boid.cpp
//  NOC_6_9_Flocking
//
//  Created by Maria Paula Saba dos Reis on 3/20/13.
//
//

#include "Boid.h"

Boid::Boid(){

}

void Boid::setup(int x, int y){
    location.set(x, y);
    velocity.set(ofRandom(-1, 1), ofRandom(-1, 1));
    acceleration.set(0, 0);
    r = 2;
    topSpeed = 6;
    maxForce = 0.1;
}


void Boid::update(){
    velocity += acceleration;
    velocity.limit(topSpeed);
    location += velocity;
    acceleration *= 0;
    
}

void Boid::applyForce(const ofVec2f & force) {
    ofVec2f f(force);
    acceleration += f;
}

void Boid::flock(vector<Boid*> boids) {
    ofVec2f sep = separate(boids);  
    ofVec2f ali = align(boids);         ofVec2f coh = cohesion(boids);
    // Arbitrarily weight these forces
    sep *= 1.5;
    ali *= 1.0;
    coh *= 1.0;
 
    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}

ofVec2f Boid::separate (vector<Boid*> boids) {
    float desiredseparation = 25.0f;
    ofVec2f sum;
    int count = 0;
    
    
    for (int i = 0; i < boids.size(); i++) {
        
        float d = (location - boids[i]->getLocation()).length();
        
        if ((d > 0) && (d < desiredseparation)) {
            
            ofVec2f diff = location - boids[i]->getLocation();
            diff.normalize();
            diff /= d;
            sum += diff;
            count++;            
        }
    }

    if (count > 0) {
        sum /= count;
      
        if (sum.length() > 0){
            sum.normalize();
            sum *= topSpeed;
            
            ofVec2f steer = sum - velocity;
            steer.limit(maxForce);
            return steer;
        }
    }
    return ofVec2f(0, 0);
}

ofVec2f Boid::align (vector<Boid*> boids) {
    float neighbordist = 50;
    ofVec2f sum = ofVec2f(0,0);
    int count = 0;
    
    for (int i = 0; i < boids.size(); i++) {
        
        float d = (location - boids[i]->getLocation()).length();

        if ((d > 0) && (d < neighbordist)) {
            sum += boids[i]->getVelocity();
            count++;
        }
    }
    if (count > 0) {
        sum /= (float)count;
        sum.normalize();
        sum *= topSpeed;
        ofVec2f steer = sum - velocity;
        steer.limit(maxForce);
        return steer;
    } else {
        return ofVec2f(0,0);
    }
}

ofVec2f Boid::cohesion (vector<Boid*> boids) {
    float neighbordist = 50;
    ofVec2f sum = ofVec2f(0,0);   // Start with empty vector to accumulate all locations
    int count = 0;
    
    for (int i = 0; i < boids.size(); i++) {
        
        float d = (location - boids[i]->getLocation()).length();
        
        if ((d > 0) && (d < neighbordist)) {
            sum += boids[i]->getLocation(); // Add location
            count++;
        }
    }
    if (count > 0) {
        sum /= count;
        return seek(sum);  // Steer towards the location
    }
    return ofVec2f(0,0);
}


void Boid::borders() {
    if (location.x < -r) location.x = ofGetWidth()+r;
    if (location.y < -r) location.y = ofGetHeight()+r;
    if (location.x > ofGetWidth()+r) location.x = -r;
    if (location.y > ofGetHeight()+r) location.y = -r;
}

ofVec2f Boid::seek(const ofVec2f & target) {
    ofVec2f desired = target - location;  // A vector pointing from the location to the target
    
    // Normalize desired and scale to maximum speed
    desired.normalize();
    desired *= topSpeed;
    // Steering = Desired minus velocity
    ofVec2f steer = desired - velocity;
    steer.limit(maxForce);  // Limit to maximum steering force
    
    return steer;
}

void Boid::draw(){
    // Draw a triangle rotated in the direction of velocity
    float theta = ofVec2f(1, 0).angle(velocity) + 90;
    ofPushMatrix();
    ofTranslate(location.x,location.y);
    ofRotate(theta);
    ofBeginShape();
    ofFill();
    ofSetColor(127);
    ofVertex(0, -r*2);
    ofVertex(-r, r*2);
    ofVertex(r, r*2);
    ofEndShape(true);
    // stroke
    ofBeginShape();
    ofNoFill();
    ofSetColor(0);
    ofVertex(0, -r*2);
    ofVertex(-r, r*2);
    ofVertex(r, r*2);
    ofEndShape(true);
    
    ofPopMatrix();
}
