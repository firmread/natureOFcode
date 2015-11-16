//
//  liquid.cpp
//  NOC_2_5_fluidresistance
//
//  Created by Firm Read on 2/22/13.
//
//

#include "liquid.h"

void liquid::setup(float x_, float y_, float w_, float h_, float c_){
    x = x_;
    y = y_;
    w = w_;
    h = h_;
    c = c_;
}

bool liquid::contains(mover m){
    ofPoint l = m.location;
    if (l.x > x && l.x < x +w && l.y > y && l.y < y + h) {
        return true;
    }
    else {
        return false;
    }
}

ofPoint liquid::drag(mover m){
    float speed = m.velocity.length();
    float dragLength = c * speed * speed;
    
    ofPoint dragForce = m.velocity;
    dragForce *= -1;
    
    //dragForce.length = dragLength;
    dragForce.normalize();
    dragForce *= dragLength;
    return dragForce;
}

void liquid::display(){
    ofSetColor(50);
    ofDrawRectangle(x, y, w, h);
}