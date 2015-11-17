//
//  mover.cpp
//  NOC_3_11_Spring
//
//  Created by Maria Paula Saba dos Reis on 2/18/13.
//
//

#include "mover.h"
#include "Spring.h"


void mover::setup(float x, float y){
    location.set(x, y);
    velocity.set(0,0);
    acceleration.set(0,0);
    dragOffset.set(0,0);
    
    mass = 44;
    damping = 0.995;

    dragging = false;

}

void mover::update(){
    velocity += acceleration;
    velocity *= damping;
    location += velocity;
    
    acceleration *= 0;
}

void mover::applyForce(const ofPoint & force){
    ofPoint f(force/mass);
    acceleration += f;

}

//void mover::airResistance(){
//    float c = 0.02;
//    
//    float speed = velocity.length();
//    float dragMagnitude = c * speed * speed;
//    
//    ofPoint drag;
//    drag.set(velocity);
//    drag *= -1;
//    drag.normalize();
//    
//    
//    drag *= dragMagnitude;
//    applyForce(drag);
//}

void mover::display(){
    if (dragging) ofSetColor(0);
    else  ofSetColor(127);
    ofDrawCircle(location.x, location.y, mass);
}

void mover::clicked(int mx, int my){
    float d = ofDist(mx, my, location.x, location.y);
    if(d< mass){
        dragging = true;
        dragOffset.x = location.x-mx;
        dragOffset.y = location.y-my;
    }
}

void mover::stopDragging(){
    dragging = false;
}
    
void mover::drag(int mx, int my){
    if(dragging){
        location.x = mx + dragOffset.x;
        location.y = my + dragOffset.y;
    }
}




