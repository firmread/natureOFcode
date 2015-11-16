//
//  Spring.cpp
//  NOC_3_11_Spring
//
//  Created by Maria Paula Saba dos Reis on 2/18/13.
//
//

#include "Spring.h"


void Spring::setup(float x, float y, int l){
    anchor.set(x,y);
    len = l;
    k = 0.02;

}




void Spring::connect(Bob  & b){
    
    
    
    ofVec2f springForce;
    springForce = b.location - anchor;
    
    float d = springForce.length();
    float stretch = d - len;
    
    springForce.normalize();
    springForce = springForce * -1 * k * stretch;
    
    
    b.applyForce(springForce);
}






void Spring::display(Bob & b){

    ofVec2f springForce;
    springForce = b.location - anchor;
    
    float d = springForce.length();
    float s = d - len;
   
    
    ofSetColor(0);
    ofSetLineWidth(5);
    ofNoFill();
    
    ofCurve(anchor.x+s, anchor.y+s, anchor.x, anchor.y, b.location.x, b.location.y, b.location.x-s, b.location.y-s);
       
   
 //   ofLine(b.location.x, b.location.y, anchor.x, anchor.y);
    ofSetLineWidth(1);

   
}


void Spring::constrainLength(Bob b, float minLen, float maxLen){
    ofVec2f dir;
    dir = b.location - anchor;
    
    float d = dir.length();
    
    if(d < minLen){
        dir.normalize();
        dir *= minLen;
        
        b.location = anchor + dir;
        b.velocity *= 0;
    }
    
    else if(d > maxLen){
        dir.normalize();
        dir *= maxLen;
        
        b.location = anchor + dir;
        b.velocity *= 0;
        
    }
}
