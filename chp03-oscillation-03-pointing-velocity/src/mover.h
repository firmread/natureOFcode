#pragma once

class mover {
public:
    
    ofPoint location, velocity, acceleration;
    float topspeed, xoff, yoff, r = 16;
    
    mover() {
        location.set(ofGetWidth()/2, ofGetHeight()/2);
        velocity.set(0,0);
        topspeed = 4;
        xoff = 1000;
        yoff = 0;
    }
    
    void update() {
        
        ofPoint mouse(ofGetMouseX(), ofGetMouseY());
        ofPoint dir(mouse-location);
        dir.normalize();
        dir *= 0.5;
        acceleration = dir;
        
        velocity += acceleration;
        velocity.limit(topspeed);
        location += velocity;
    }
    
    void display() {
        
        ofPoint v1(location);
        ofPoint v2(velocity);
        float theta = v1.angle(v2);
        
        ofPushMatrix();
        ofRectMode(OF_RECTMODE_CENTER);
        ofTranslate(location.x, location.y);
        ofRotate(theta);

        ofSetColor(127);
        ofDrawRectangle(0, 0, 30, 10);
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
