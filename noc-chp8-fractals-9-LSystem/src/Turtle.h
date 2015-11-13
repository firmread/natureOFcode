// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

#pragma once
#include "ofMain.h"

class Turtle {
public:
    Turtle(string s, float l, float t) {
        todo = s;
        len = l;
        theta = t;
    }
    
    void render() {
        ofNoFill();
        ofSetColor(0,175);
        for (int i = 0; i < todo.length(); i++) {
            char c = todo.at(i);
            if (c == 'F' || c == 'G') {
                ofLine(0,0,len,0);
                ofTranslate(len,0);
            }
            else if (c == '+') {
                ofRotateZ(ofRadToDeg(theta));
            }
            else if (c == '-') {
                ofRotateZ(ofRadToDeg(-theta));
            }
            else if (c == '[') {
                ofPushMatrix();
            }
            else if (c == ']') {
                ofPopMatrix();
            }
        }
    }
    
    void setLen(float l) {
        len = l; 
    } 
    
    void changeLen(float percent) {
        len *= percent; 
    }
    
    void setToDo(string s) {
        todo = s; 
    }
    
protected:
    
    string todo;
    float len;
    float theta;
};


