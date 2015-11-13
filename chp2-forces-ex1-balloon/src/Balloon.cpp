#include "Balloon.h"

Balloon::Balloon() {
    location = ofVec2f(ofRandom((float)(ofGetWindowWidth()/2)),ofRandom((float)(ofGetWindowHeight()/2)));
    velocity = ofVec2f(0,0);
    acceleration = ofVec2f(0,0);
}

void Balloon::applyForce(ofVec2f f) {
    acceleration += f;
}

void Balloon::display(){
    ofSetColor(0,0,255);
    ofFill();
    ofCircle(location.x, location.y, 16);
}

void Balloon::update() {
    checkEdges();
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
}

void Balloon::setPosition(int posX, int posY) {
    location.x = (float)posX;
    location.y = (float)posY;
}

void Balloon::checkEdges() {
    ofVec2f wallForce;
    if (location.x > ofGetWindowWidth()) {
      location.x = ofGetWindowWidth();
      wallForce.set(velocity.x * -1.5f,0.0f);
      applyForce(wallForce);
    } else if (location.x < 0) {
      location.x = 0;
      wallForce.set(velocity.x * -1.5f,0.0f);
      applyForce(wallForce);
    }

    if (location.y > ofGetWindowHeight()) {
      location.y = ofGetWindowHeight();
      wallForce.set(0.0f,velocity.y * -1.9f);
      applyForce(wallForce);
    } else if (location.y < 0) {
      location.y = 0;
      wallForce.set(0.0f,velocity.y * -1.9f);
      applyForce(wallForce);
    }
  }
