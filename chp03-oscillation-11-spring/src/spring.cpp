#include "spring.h"


void spring::setup(float x, float y, int l){
    anchor.set(x,y);
    len = l;

    k = 0.05;
}

void spring::connect(mover & m){
    
    ofPoint springForce;
    springForce = m.location - anchor;
    
    float d = springForce.length();
    float stretch = d - len;
    
    springForce.normalize();
    springForce = springForce * -1 * k * stretch;
    
    
    m.applyForce(springForce);
}


void spring::constrainLength(mover m, float minLen, float maxLen){
    ofPoint dir(m.location - anchor);
    float d = dir.length();
    
    if(d < minLen){
        dir.normalize();
        dir *= minLen;
        
        m.location = anchor + dir;
        m.velocity *= 0;
    }
    
    else if(d > maxLen){
        dir.normalize();
        dir *= maxLen;
        
        m.location = anchor + dir;
        m.velocity *= 0;
        
    }
}


void spring::display(mover & m){

    ofSetColor(0);
    ofSetLineWidth(3);
    ofDrawLine(m.location.x, m.location.y, anchor.x, anchor.y);
    
    ofSetColor(127);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(anchor, 20, 20);
}
