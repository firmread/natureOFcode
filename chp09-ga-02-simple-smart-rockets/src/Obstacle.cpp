#include "Obstacle.h"

Obstacle::Obstacle(ofPoint _location,ofPoint _dimensions){
    location = _location;
    dimensions = _dimensions;
}

void Obstacle::display() {
    ofSetColor(127,127,127);
    ofRect(location.x,location.y,dimensions.x,dimensions.y);
}

bool Obstacle::contains(ofPoint v) {
    if (v.x > location.x && v.x < location.x + dimensions.x && v.y > location.y && v.y < location.y + dimensions.y) {
      return true;
    } else {
      return false;
    }
}

