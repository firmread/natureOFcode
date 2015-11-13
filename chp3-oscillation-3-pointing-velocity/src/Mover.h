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
    
    ofVec2f location, velocity, acceleration;
    float topspeed, xoff, yoff, r = 16;
    
    Mover() {
        location.set(ofGetWidth()/2, ofGetHeight()/2);
        velocity.set(0,0);
        topspeed = 4;
        xoff = 1000;
        yoff = 0;
    }
    
    void update() {
        
        ofVec2f mouse;
        mouse.set(ofGetMouseX(), ofGetMouseY());
        ofVec2f dir;
        dir.set(mouse);
        dir -= location;
        dir.normalize();
        dir *= 0.5;
        acceleration = dir;
        
        velocity += acceleration;
        velocity.limit(topspeed);
        location += velocity;
    }
    
    void display() {
        
        ofVec2f v1(location);
        ofVec2f v2(velocity);
        float theta = v1.angle(v2);
        
        ofSetLineWidth(2);
        
        
        
        ofPushMatrix();
        ofRectMode(OF_RECTMODE_CENTER);
        ofTranslate(location.x, location.y);
        ofRotate(theta);

        ofNoFill();
        ofSetColor(0);
        ofRect(0, 0, 30, 10);
        
        ofFill();
        ofSetColor(127);
        ofRect(0, 0, 30, 10);
        ofPopMatrix();
    }
    
    void checkEdges() {
        
        if (location.x > ofGetWidth()) {
            location.x = 0;
        }
        else if (location.x < 0) {
            location.x = ofGetWidth();
        }
        
        if (location.y > ofGetHeight()) {
            location.y = 0;
        } 
        else if (location.y < 0) {
            location.y = ofGetHeight();
        }
    }

};


#endif
