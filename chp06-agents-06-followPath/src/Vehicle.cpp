//
//  Vehicle.cpp
//  NOC_6_1_Seek_trail
//
//  Created by Maria Paula Saba on 3/17/13.
//
//

#include "Vehicle.h"


void Vehicle::setup(ofVec2f & l, float ts, float mf){
    
    r = 4;
    maxForce = mf;
    topSpeed =ts;
    
    acceleration.set(0, 0);
    velocity.set(ts, 0.0);
    location = l;
    
    debug = false;
    
}




void Vehicle::applyForce(const ofVec2f & force){
    ofVec2f f(force);
    acceleration += f;
}


void Vehicle::follow(Path & p){
    radius = p.radius;
    
    // Predict location 25 (arbitrary choice) frames ahead
    ofVec2f predict(velocity);
    predict.normalize();
    predict *= 25;
    
    predictLoc = location + predict;

   
    worldRecord = 1000000;
    
    // Loop through all points of the path
    for (unsigned int i = 0; i < p.points.size()-1; i++) {
        
        // Look at a line segment
        ofVec2f a(p.points[i]);
        ofVec2f b(p.points[i+1]);
        
        // Get the normal point to that line
        ofVec2f normalPoint = getNormalPoint(predictLoc, a, b);
        
        
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
                
                ofVec2f dir = b - a;
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


ofVec2f Vehicle::getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b){
    ofVec2f ap = p-a;
    ofVec2f ab = b-a;
    
    ab.normalize();
    ab*=ap.dot(ab);
    ofVec2f normalPoint = a + ab;
    return normalPoint;


}


void Vehicle::seek(const ofVec2f & target){
    ofVec2f desired;
    desired = target - location;
    
    if(desired.length() == 0) return;
    
    
    desired.normalize();
    desired*=topSpeed;
    
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
    
    
}

void Vehicle::draw(){
    
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
    ofNoFill();
    ofLine(location.x, location.y, predictLoc.x, predictLoc.y);
    
    ofSetColor(0);
    ofFill();
    ofEllipse(predictLoc.x, predictLoc.y, 4, 4);
    
    // Draw normal location
    ofSetColor(0);
    ofFill();
    ofEllipse(normal.x, normal.y, 4, 4);
    // Draw actual target (red if steering towards it)
    ofNoFill();
    ofLine(predictLoc.x, predictLoc.y, normal.x, normal.y);
    
        
        if (worldRecord > radius){
            ofSetColor(255, 0, 0);
            ofFill();
            ofEllipse(target.x, target.y, 4, 4);
        }
    
    }
    
 
    
}


void Vehicle::borders(){

    if (location.x < -r) location.x = ofGetWidth()+r;
    //if (location.y < -r) location.y = height+r;
    if (location.x > ofGetWidth()+r) location.x = -r;
    //if (location.y > height+r) location.y = -r;
}

