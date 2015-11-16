#pragma once
class mover {
public:
    
    ofPoint location, acceleration, velocity;
    float mass, angle = 0, aVelocity = 0, aAcceleration = 0;
    
    mover() {
        
    }
    
    mover(float m, float x, float y) {
        mass = m;
        location.set(x,y);
        velocity.set(ofRandom(-1,1),ofRandom(-1,1));
        acceleration.set(0,0);
    }
    
    void applyForce(ofPoint force) {
        ofPoint f(force);
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
        ofSetColor(175,200);
        ofSetRectMode(OF_RECTMODE_CENTER);
        
        ofPushMatrix();
        ofTranslate(location.x,location.y);
        ofRotate(ofRadToDeg(angle));
        ofDrawRectangle(0, 0, mass * 8, mass * 8);
        ofPopMatrix();
    }
    
};

