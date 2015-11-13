//
//  Mover.h
//  NOC_3_02_forces_angular_motion
//
//  Created by Jason McDermott on 31/01/13.
//
//

#ifndef NOC_3_02_forces_angular_motion_Mover_h
#define NOC_3_02_forces_angular_motion_Mover_h


class Mover {
public:
    
    ofVec2f location, acceleration, velocity;
    float mass, angle = 0, aVelocity = 0, aAcceleration = 0;
    
    Mover() {
        
    }
    
    Mover(float m, float x, float y) {
        mass = m;
        location.set(x,y);
        velocity.set(ofRandom(-0.1,0.1),ofRandom(-0.1,0.1));
        velocity.set(0,0);
        acceleration.set(0,0);
    }
    
    void applyForce(ofVec2f force) {
        ofVec2f f;
        f.set(force);
        f /= mass;
        acceleration += f;
    }
    
    void update() {
        velocity += acceleration;
        location += velocity;
        
        aAcceleration = acceleration.x / 10.0;
        aVelocity += aAcceleration;
        aVelocity = ofClamp(aVelocity,-0.1,0.1);
        angle += aVelocity;
        acceleration.set(0,0);
    }
    
    void display() {
        
        
//        rectMode(CENTER);
        ofSetColor(175,200);
        ofPushMatrix();
        ofTranslate(location.x,location.y);
        ofRotate(angle);
        ofNoFill();
        ofSetColor(0);
        ofRect(0, 0, mass * 8, mass * 8);
        
        ofFill();
        ofSetColor(175,200);
        ofRect(0, 0, mass * 8, mass * 8);
        ofPopMatrix();
    }
    
};


#endif
