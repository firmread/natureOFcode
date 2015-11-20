#include "boid.h"


void boid::setup(int x, int y){
    location.set(x, y);
    velocity.set(ofRandom(-1, 1), ofRandom(-1, 1));
    acceleration.set(0, 0);
    r = 5;
    topSpeed = 3;
    maxForce = 0.05;
}


void boid::update(){
    velocity += acceleration;
    velocity.limit(topSpeed);
    location += velocity;
    acceleration *= 0;
    
}

void boid::applyForce(const ofPoint & force) {
    ofPoint f(force);
    acceleration += f;
}

void boid::flock(vector<boid> boids) {
    ofPoint sep = separate(boids);  
    ofPoint ali = align(boids);         ofPoint coh = cohesion(boids);
    // Arbitrarily weight these forces
    sep *= 1.5;
    ali *= 1.0;
    coh *= 1.0;
 
    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}

ofPoint boid::separate (vector<boid> boids) {
    float desiredseparation = 25.0f;
    ofPoint sum;
    int count = 0;
    
    
    vector<boid>::iterator other;
    for (other = boids.begin(); other < boids.end(); other++) {
        float d = (location - other->getLocation()).length();
        
        if ((d > 0) && (d < desiredseparation)) {
            
            ofPoint diff = location - other->getLocation();
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
            
            ofPoint steer = sum - velocity;
            steer.limit(maxForce);
            return steer;
        }
    }
    return ofPoint(0, 0);
}

ofPoint boid::align (vector<boid> boids) {
    float neighbordist = 50;
    ofPoint sum = ofPoint(0,0);
    int count = 0;
    vector<boid>::iterator other;
    for (other = boids.begin(); other < boids.end(); other++) {
        float d = (location - other->getLocation()).length();
        if ((d > 0) && (d < neighbordist)) {
            sum += other->getVelocity();
            count++;
        }
    }
    if (count > 0) {
        sum /= (float)count;
        sum.normalize();
        sum *= topSpeed;
        ofPoint steer = sum - velocity;
        steer.limit(maxForce);
        return steer;
    } else {
        return ofPoint(0,0);
    }
}

ofPoint boid::cohesion (vector<boid> boids) {
    float neighbordist = 50;
    ofPoint sum = ofPoint(0,0);   // Start with empty vector to accumulate all locations
    int count = 0;
    vector<boid>::iterator other;
    for (other = boids.begin(); other < boids.end(); other++) {
        float d = (location - other->getLocation()).length();
        if ((d > 0) && (d < neighbordist)) {
            sum += other->getLocation(); // Add location
            count++;
        }
    }
    if (count > 0) {
        sum /= count;
        return seek(sum);  // Steer towards the location
    }
    return ofPoint(0,0);
}


void boid::borders() {
    if (location.x < -r) location.x = ofGetWidth()+r;
    if (location.y < -r) location.y = ofGetHeight()+r;
    if (location.x > ofGetWidth()+r) location.x = -r;
    if (location.y > ofGetHeight()+r) location.y = -r;
}

ofPoint boid::seek(const ofPoint & target) {
    ofPoint desired = target - location;  // A vector pointing from the location to the target
    
    // Normalize desired and scale to maximum speed
    desired.normalize();
    desired *= topSpeed;
    // Steering = Desired minus velocity
    ofPoint steer = desired - velocity;
    steer.limit(maxForce);  // Limit to maximum steering force
    
    return steer;
}

void boid::draw(){
    // Draw a triangle rotated in the direction of velocity
    float theta = ofRadToDeg(atan2(velocity.y,velocity.x)) + 90;
    ofPushMatrix();
        ofTranslate(location.x,location.y);
        ofRotate(theta);
        ofBeginShape();
        ofSetColor(0,127);
        ofVertex(0, -r*2);
        ofVertex(-r, r*2);
        ofVertex(r, r*2);
        ofEndShape();
    
    ofPopMatrix();
}
