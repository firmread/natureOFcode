#include "Vehicle.h"
#include "ofApp.h"

Vehicle::Vehicle(int n, float x,float y){
    brain = Perceptron(n,0.01);
    acceleration = ofPoint(0,0);
    velocity = ofPoint(0,0);
    location = ofPoint(x,y);
    r = 12.0;
    maxspeed = 2.0;
    maxforce = 0.1;
}

void Vehicle::update(){
    velocity += acceleration;
    velocity.limit(maxspeed);
    location += velocity;
    acceleration *= 0;
}

void Vehicle::applyForce(ofPoint force) {
    acceleration += force;
}

void Vehicle::steer(vector<Target> targets){
    vector<ofPoint> forces;

    for (int i = 0; i < targets.size(); i++) {

      ofPoint targetLocation = targets[i].getLocation();
      ofPoint seekResult = seek(targetLocation);

      forces.push_back(seekResult);

      ofPoint halfWay = (targetLocation - location)/2 + location;
      ofSetColor(0,0,0,255);
      ofDrawBitmapString("X: " + ofToString(seekResult.x,3) + " y: " + ofToString(seekResult.y,3), halfWay.x,halfWay.y);
      ofSetColor(255,0,0,55);
      ofLine(targetLocation.x,targetLocation.y,location.x,location.y);

    }
    // All the steering forces are inputs.
    ofPoint result = brain.feedforward(forces);

    //The result is applied.
    applyForce(result);

    // The brain is trained according to the distance to the center.
    ofPoint desired = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
    ofPoint error = desired - location;
    brain.train(forces,error);
}


ofPoint Vehicle::seek(ofPoint targetLocation) {
    ofPoint desired = targetLocation - location;
    desired.normalize();
    desired *= maxspeed;
    ofPoint steer = desired - velocity;
    steer.limit(maxforce);
    return steer;
}

void Vehicle::display() {
    float theta = velocity.angle(ofPoint(0,1));
    ofFill();
    ofPushMatrix();
     ofTranslate(location.x,location.y);
     ofRotate(-theta);

     ofSetColor(0,0,0,175);
     ofBeginShape();
     ofVertex(0, r*2);
     ofVertex(-r, -r*2);
     ofVertex(r, -r*2);
     ofEndShape();

    ofPopMatrix();
}
