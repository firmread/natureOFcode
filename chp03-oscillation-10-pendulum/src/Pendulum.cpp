
#include "Pendulum.h"


void Pendulum::setup(ofVec2f orig, float len){
    origin.set(orig.x, orig.y);
    location.set(0,0);
    length = len;
    angle = PI/4;
    
    velocity = 0.0;
    acceleration = 0.0;
    damping = 0.999;
    ballRadius = 64;
    
    dragging = false;

}




void Pendulum::update(){
    if(!dragging){
    float gravity = 0.4;
    acceleration = (-1*gravity / length)*sin(angle);
    
    velocity += acceleration;
    angle += velocity;
    
    velocity *= damping;
    }
    
    
}
void Pendulum::display(){
    
    location.set(length*sin(angle), length*cos(angle));
    location += origin;
    
    ofSetColor(0);
    ofNoFill();
    ofLine(origin.x, origin.y, location.x, location.y);
    
    if (dragging) ofSetColor(0);
    else  ofSetColor(175);
    ofFill();
    ofCircle(location.x, location.y, ballRadius);
    
    
}


void Pendulum::drag(){
    if(dragging){
        ofVec2f diff;
        ofVec2f mouse;
        mouse.set(ofGetMouseX(), ofGetMouseY());
        
        diff = origin - mouse;
        
        angle = atan2(-1*diff.y, diff.x) - ofDegToRad(90);
    
    }

}


void Pendulum::clicked(int mx, int my){
    float d = ofDist(mx, my, location.x, location.y);
    if(d< ballRadius){
        dragging = true;
    }
}

void Pendulum::stopDragging(){
    if(dragging){
    velocity = 0;
    dragging = false;
    }

}