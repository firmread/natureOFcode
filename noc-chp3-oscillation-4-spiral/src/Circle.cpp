//
//  Circle.cpp
//  NOC_3_4_spiral
//
//  Created by Maria Paula Saba dos Reis on 2/13/13.
//
//

#include "Circle.h"
#include "testApp.h"

void Circle::setup(){}




void Circle::update(){

    x = r * cos(theta);
    y = r * sin(theta);
    
    theta += 0.01;
    r += 0.09;
    
    angle += 0.1;

}

void Circle::draw(){
    ofSetCircleResolution(50);
    ofSetColor(0);
    ofFill();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofCircle(x, y, 16, 16);
}