#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "ofMain.h"

void drawMyCircle(int x, int y, float radius) {
  ofSetColor(0,0,0);
  ofNoFill();
  ofCircle(x, y, radius);
  if(radius > 2) {
    radius *= 0.75f;
    // The drawCircle() function is calling itself recursively.
    drawMyCircle(x, y, radius);
  }
}

#endif // CIRCLE_H_INCLUDED

