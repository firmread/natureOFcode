#include "KochCurve.h"

KochCurve::KochCurve(ofPoint a, ofPoint b,int iterations) {
    KochLine kl = KochLine(a,b);
    lines.push_back(kl);
    for(int i = 0; i < iterations; i++) {
        generateLines();
    }
}

void KochCurve::display() {
    ofSetColor(0,0,0);
    for(int i = 0;  i < lines.size(); i++ ) {
        lines[i].display();
    }
}

void KochCurve::generateLines(){
  std::vector<KochLine> next;

    // for every current line.
  for(int i = 0;  i < lines.size(); i++ ) {
    // Add four new lines.

    ofPoint a = lines[i].kochA();
    ofPoint b = lines[i].kochB();
    ofPoint c = lines[i].kochC();
    ofPoint d = lines[i].kochD();
    ofPoint e = lines[i].kochE();

    next.push_back( KochLine(a,b));
    next.push_back( KochLine(b,c));
    next.push_back( KochLine(c,d));
    next.push_back( KochLine(d,e));

  }

  // The new ArrayList is now the one we care about!
  lines = next;
}

/*
* LINE FUNCTIONS
*/

KochCurve::KochLine::KochLine(ofPoint a, ofPoint b) {
    startPt = a;
    endPt = b;
}

ofPoint KochCurve::KochLine::kochA(){
    return startPt;
}

ofPoint KochCurve::KochLine::kochB(){
    ofPoint v = endPt - startPt;
    // One-third the length
    v /= 3;
    // Add that PVector to the beginning of the line to find the new point.
    v += startPt;
    return v;
}

ofPoint KochCurve::KochLine::kochC(){
    ofPoint a = startPt;
    ofPoint v = endPt - startPt;
    // Move 1/3rd of the way to point B.
    v /= 3;
    a += v;
    // Rotate “above” the line 60 degrees.
    v.rotate(-60, *new ofVec3f(0,0));
    // Move along that vector to point C.
    a += v ;
    return a;
}

ofPoint KochCurve::KochLine::kochD(){
    ofPoint v = endPt - startPt;
    // Same thing here, only we need to move two-thirds along the line instead of one-third.
    v *= (2/3.0);
    v += startPt;
    return v;
}

ofPoint KochCurve::KochLine::kochE(){
    return endPt;
}

void KochCurve::KochLine::display() {
    ofLine(startPt.x, startPt.y, endPt.x, endPt.y);
}

