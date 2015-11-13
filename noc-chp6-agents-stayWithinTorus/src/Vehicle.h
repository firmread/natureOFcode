//
//  Oscillator.h
//  NOC_3_07_oscillating_objects
//
//  Created by Jason McDermott on 3/02/13.
//
//

#ifndef NOC_3_07_stayWithinCircle_h
#define NOC_3_07_stayWithinCircle_h


class Vehicle {
public:

    ofVec3f acceleration, velocity, location, futureLocation;
    float maxspeed, maxforce, r;
    
    Vehicle(){
        
    }
    
    Vehicle(float x, float y, float z) {
        acceleration.set(0, 0, 0);
        velocity.set(ofRandom(-1,1),ofRandom(-1,1), ofRandom(-1,1));
        velocity *= 5;
        location.set(x, y, z);
        r = 3;
        maxspeed = 3;
        maxforce = 0.15;
    }

    void run() {
        update();
        display();
    }

    // Method to update location
    void update() {
        // Update velocity
        velocity += acceleration;
        // Limit speed
        velocity.limit(maxspeed);
        location += velocity;
        // Reset accelertion to 0 each cycle
        acceleration *= 0;
    }
    
    
    void outerBoundaries(ofVec3f circleLocation, float circleRadiusOuter) {
        
        ofVec3f desired;
        
        // Predict location 5 (arbitrary choice) frames ahead
        ofVec3f predict(velocity);
        predict *= 25;
        ofVec3f futureLocation(location);
        
        futureLocation += predict;
        
        ofVec3f distFromCircleCentre(circleLocation);
        
        distFromCircleCentre -= futureLocation;
        
        float distance = distFromCircleCentre.length();
        
        if (distance > circleRadiusOuter * 0.6) {
            
            ofVec3f toCenter(circleLocation);
            toCenter -= location;
            toCenter.normalize();
            toCenter *= velocity.length();
            toCenter += velocity;
            
            desired.set(toCenter);
            desired.normalize();
            desired *= maxspeed;
        }
        
        if (desired.length() != 0) {
            ofVec3f steer(desired);
            steer -= velocity;
            //            PVector steer = PVector.sub(desired, velocity);
            steer.limit(maxforce);
            applyForce(steer);
        }
        
        
    }
    
    void innerBoundaries(ofVec3f circleLocation, float circleRadiusInner) {
        
        ofVec3f desired;
        
        // Predict location 5 (arbitrary choice) frames ahead
        ofVec3f predict(velocity);
        predict *= 25;
        futureLocation.set(location);
        
        futureLocation += predict;
        
        ofVec3f distFromCircleCentre(circleLocation);
        
        distFromCircleCentre -= futureLocation;
        
        float distance = distFromCircleCentre.length();
        
        if (distance < circleRadiusInner * 0.6) {
            
            ofVec3f toCenter(circleLocation);
            toCenter += location;
            toCenter.normalize();
            toCenter *= velocity.length();
            toCenter += velocity;
            
            desired.set(toCenter);
            desired.normalize();
            desired *= maxspeed;
        }
        
        if (desired.length() != 0) {
            ofVec3f steer(desired);
            steer -= velocity;
            //            PVector steer = PVector.sub(desired, velocity);
            steer.limit(maxforce);
            applyForce(steer);
        }
        
    }
    
    void applyForce(ofVec3f force) {
        // We could add mass here if we want A = F / M
        acceleration += force;
    }
    
    void display() {
        // Draw a triangle rotated in the direction of velocity
//        float theta = velocity.angle() + radians(90);
        
        
//        ofVec3f v1(location);
//        ofVec3f v2(velocity);
//        float theta = v1.angle(v2) + 90 + r*10;
        
        
        ofPushMatrix();
        ofTranslate(location.x, location.y, location.z);
//        ofRotateZ(theta);

        ofFill();
        ofSetColor(255,0,200);
        ofSphere(0,0,0,r);
//        ofTriangle(0, -r*2, -r, r*2, r, r*2);     
        
//        ofSetColor(175);
//        ofTriangle(0, -r*2, -r, r*2, r, r*2);
        ofPopMatrix();
    }
    

    
};


#endif
