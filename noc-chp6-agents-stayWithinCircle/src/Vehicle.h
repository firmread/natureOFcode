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

    ofVec2f acceleration, velocity, location;
    float maxspeed, maxforce, r;
    ofVec2f circleLocation;
    float circleRadius;
    
    Vehicle(){
        
    }
    
    Vehicle(float x, float y, ofVec2f circleLocation_, float circleRadius_) {
        acceleration.set(0, 0);
        velocity.set(ofRandom(-1,1),ofRandom(-1,1));
        velocity *= 5;
        location.set(x, y);
        r = 3;
        maxspeed = 3;
        maxforce = 0.15;
        circleLocation.set(circleLocation_);
        circleRadius = circleRadius_;
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
    
    
    void boundaries() {
        
        ofVec2f desired;
        
        // Predict location 5 (arbitrary choice) frames ahead
        ofVec2f predict(velocity);
        predict *= 25;
        ofVec2f futureLocation(location);
        
        futureLocation += predict;
        
        ofVec2f distFromCircleCentre(circleLocation);
        
        distFromCircleCentre -= futureLocation;
        
        float distance = distFromCircleCentre.length();
        
        if (distance > circleRadius * 0.6) {
            
            ofVec2f toCenter(circleLocation);
            toCenter -= location;
            toCenter.normalize();
            toCenter *= velocity.length();
            toCenter += velocity;
            
            desired.set(toCenter);
            desired.normalize();
            desired *= maxspeed;
        }
        
        if (desired.length() != 0) {
            ofVec2f steer(desired);
            steer -= velocity;
//            PVector steer = PVector.sub(desired, velocity);
            steer.limit(maxforce);
            applyForce(steer);
        }
    
        ofSetColor(255,0,0);
        ofCircle(futureLocation.x,futureLocation.y,4,4);
        
    }
    
    void applyForce(ofVec2f force) {
        // We could add mass here if we want A = F / M
        acceleration += force;
    }
    
    void display() {
        // Draw a triangle rotated in the direction of velocity
//        float theta = velocity.angle() + radians(90);
        
        
        ofVec2f v1(location);
        ofVec2f v2(velocity);
        float theta = v1.angle(v2) + 90 + r*10;
        
        
        ofPushMatrix();
        ofTranslate(location.x, location.y);
        ofRotateZ(theta);

        
        ofSetColor(0);
        ofTriangle(0, -r*2, -r, r*2, r, r*2);

//        ofBeginShape();
//        ofVertex(0, -r*2);
//        ofVertex(-r, r*2);
//        ofVertex(r, r*2);
//        ofEndShape();
    

        
        
        ofSetColor(175);
        ofBeginShape();
        ofVertex(0, -r*2);
        ofVertex(-r, r*2);
        ofVertex(r, r*2);
        ofEndShape();
        
        ofPopMatrix();
    }
    

    
};


#endif
