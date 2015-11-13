//
//  Oscillator.h
//  NOC_3_07_oscillating_objects
//
//  Created by Jason McDermott on 3/02/13.
//
//

#ifndef NOC_3_07_oscillating_objects_Oscillator_h
#define NOC_3_07_oscillating_objects_Oscillator_h


class Oscillator {
public:
    ofVec3f angle, velocity, amplitude;
    
    Oscillator() {
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
        ofSetColor(0);
        ofLine(0, 0, x, y);
        ofSetColor(127, 100);
        
        ofCircle(x * 0.925, y * 0.925, 16, 16);
        ofPopMatrix();
    }

    
};


#endif
