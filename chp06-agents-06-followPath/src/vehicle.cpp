#include "vehicle.h"
void vehicle::setup(ofPoint & l, float ts, float mf){
    
    r = 4;
    maxForce = mf;
    topSpeed =ts;
    
    acceleration.set(0, 0);
    velocity.set(ts, 0.0);
    location = l;
    
    debug = false;
    
}

void vehicle::applyForce(const ofPoint & force){
    ofPoint f(force);
    acceleration += f;
}

void vehicle::follow(path & p){
    radius = p.radius;
    
    // Predict location 25 (arbitrary choice) frames ahead
    ofPoint predict(velocity);
    predict.normalize();
    predict *= 25;
    
    predictLoc = location + predict;

   
    worldRecord = 1000000;
    
    // Loop through all points of the path
    for (unsigned int i = 0; i < p.points.size()-1; i++) {
        
        // Look at a line segment
        ofPoint a(p.points[i]);
        ofPoint b(p.points[i+1]);
        
        // Get the normal point to that line
        ofPoint normalPoint = getNormalPoint(predictLoc, a, b);
        
        
        if (normalPoint.x <= a.x || normalPoint.x >= b.x) {
            
            // This is something of a hacky solution, but if it's not within the line segment
            // consider the normal to just be the end of the line segment (point b)
            
            normalPoint.set(b.x, b.y);
        }
            
            // How far away are we from the path?
        float distance = ofDist(predictLoc.x, predictLoc.y, normalPoint.x, normalPoint.y);
        
            if (distance < worldRecord) {
                worldRecord = distance;
       
                normal = normalPoint;
                
                ofPoint dir = b - a;
                dir.normalize();
                dir *= 10;  // This could be based on velocity instead of just an arbitrary 10 pixels
                target.set(normalPoint);
                target += dir;
            }
    }
    if (worldRecord > p.radius) {
        seek(target);
    }
    cout << target.x << endl;
}

ofPoint vehicle::getNormalPoint(ofPoint p, ofPoint a, ofPoint b){
    ofPoint ap = p-a;
    ofPoint ab = b-a;
    
    ab.normalize();
    ab*=ap.dot(ab);
    ofPoint normalPoint = a + ab;
    return normalPoint;
}

void vehicle::seek(const ofPoint & target){
    ofPoint desired;
    desired = target - location;
    
    if(desired.length() == 0) return;
    
    desired.normalize();
    desired*=topSpeed;
    
    ofPoint steer;
    steer = desired - velocity;
    steer.limit(maxForce);
    
    applyForce(steer);
}

void vehicle::update(){
    velocity += acceleration;
    location += velocity;
    velocity.limit(topSpeed);
    acceleration *= 0;
}

void vehicle::draw(){
    
    ofSetColor(0);
    ofNoFill();
     
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

    if(debug){
        // Draw predicted future location
        ofSetColor(0);
        ofDrawLine(location.x, location.y, predictLoc.x, predictLoc.y);
        
        ofSetColor(0);
        ofDrawCircle(predictLoc.x, predictLoc.y, 4);
        
        // Draw normal location
        ofSetColor(0);
        ofDrawCircle(normal.x, normal.y, 4);
        // Draw actual target (red if steering towards it)
        ofDrawLine(predictLoc.x, predictLoc.y, normal.x, normal.y);
        
        if (worldRecord > radius){
            ofSetColor(255, 0, 0);
            ofDrawCircle(target.x, target.y, 4);
        }
    }
}

void vehicle::borders(){
    if (location.x < -r) location.x = ofGetWidth()+r;
    //if (location.y < -r) location.y = height+r;
    if (location.x > ofGetWidth()+r) location.x = -r;
    //if (location.y > height+r) location.y = -r;
}