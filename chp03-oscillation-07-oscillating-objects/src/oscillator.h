#pragma once
class oscillator {
public:
    ofPoint angle, velocity, amplitude;
    
    oscillator() {
        angle.set(0,0,0);
        velocity.set(ofRandom(-0.05, 0.05), ofRandom(-0.05, 0.05));
        amplitude.set(ofRandom(20,ofGetWidth()/2), ofRandom(20,ofGetHeight()/2));
    }
    
    void oscillate() {
        angle += velocity;
    }
    
    void display() {
        float x = sin(angle.x)*amplitude.x;
        float y = sin(angle.y)*amplitude.y;
        
        ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            
            ofSetColor(0,100);
            ofDrawLine(0, 0, x, y);
            
            ofSetColor(127, 100);
            ofDrawCircle(x, y, 16);
        ofPopMatrix();
    }

    
};

