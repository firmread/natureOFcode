#include "vehicle.h"
void vehicle::setup(ofPoint & l, float ts, float mf){
    r = 8;
    maxForce = mf;
    maxSpeed =ts;
    
    acceleration.set(0, 0);
    velocity.set(ts, 0.0);
    location = l;
    
    debug = false;
}

void vehicle::applyForce(const ofPoint & force){
    ofPoint f(force);
    acceleration += f;
}

ofPoint vehicle::separate(vector<vehicle> vehicles){
    float desiredseparation = r*2;
    
    ofPoint sum(0,0,0);
    int count = 0;
    
    vector<vehicle>::iterator other;
    for (other = vehicles.begin(); other < vehicles.end(); other++){
        
        float d = (location - other->getLocation()).length();
        
        if((d>0) && (d < desiredseparation)){
            ofPoint diff = location - other->getLocation();
            diff.normalize();
            diff /= d;
            sum+= diff;
            count ++;
        }
    }
    
    if(count > 0){
        sum/=((float)count);
    }
    
    if(sum.length() > 0){
        sum.normalize();
        sum*=maxSpeed;
        
        sum -= velocity;
        sum.limit(maxForce);
    }
    
    return sum;
}

void vehicle::applyBehaviours(vector<vehicle> vehicles, path & p){
    
    ofPoint separateForce = separate(vehicles);
    ofPoint followForce = follow(p);
    
    followForce*=3;
    separateForce *= 1;
    
    applyForce(separateForce);
    applyForce(followForce);
}

ofPoint vehicle::follow(path & p){
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
        return seek(target);
    }
    return ofPoint(0,0);
}

ofPoint vehicle::getNormalPoint(ofPoint p, ofPoint a, ofPoint b){
    ofPoint ap = p-a;
    ofPoint ab = b-a;
    
    ab.normalize();
    ab*=ap.dot(ab);
    ofPoint normalPoint = a + ab;
    return normalPoint;
}

ofPoint vehicle::seek(const ofPoint & target){
    ofPoint desired;
    desired = target - location;
    
    if(desired.length() == 0) return;
    
    desired.normalize();
    desired*=maxSpeed;
    
    ofPoint steer;
    steer = desired - velocity;
    steer.limit(maxForce);
    
    return steer;
}

void vehicle::update(){
    velocity += acceleration;
    location += velocity;
    velocity.limit(maxSpeed);
    acceleration *= 0;
}

void vehicle::draw(){
    ofPushMatrix();
        ofSetColor(0,127);
        ofTranslate(location.x, location.y);
        //ofRotate(angle);
        ofDrawCircle(0, 0, r);
    ofPopMatrix();
}

void vehicle::borders(){
    if (location.x < -r) location.x = ofGetWidth()+r;
    if (location.y < -r) location.y = ofGetHeight()+r;
    if (location.x > ofGetWidth()+r) location.x = -r;
    if (location.y > ofGetHeight()+r) location.y = -r;
}

