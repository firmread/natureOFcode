#include "KochCurve.h"

KochCurve::KochCurve(ofVec2f a, ofVec2f b,int iterations) {
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

    ofVec2f a = lines[i].kochA();
    ofVec2f b = lines[i].kochB();
    ofVec2f c = lines[i].kochC();
    ofVec2f d = lines[i].kochD();
    ofVec2f e = lines[i].kochE();

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

KochCurve::KochLine::KochLine(ofVec2f a, ofVec2f b) {
    startPt = a;
    endPt = b;
}

ofVec2f KochCurve::KochLine::kochA(){
    return startPt;
}

ofVec2f KochCurve::KochLine::kochB(){
    ofVec2f v = endPt - startPt;
    // One-third the length
    v /= 3;
    // Add that PVector to the beginning of the line to find the new point.
    v += startPt;
    return v;
}

ofVec2f KochCurve::KochLine::kochC(){
    ofVec2f a = startPt;
    ofVec2f v = endPt - startPt;
    // Move 1/3rd of the way to point B.
    v /= 3;
    a += v;
    // Rotate “above” the line 60 degrees.
    v.rotate(-60);
    // Move along that vector to point C.
    a += v ;
    return a;
}

ofVec2f KochCurve::KochLine::kochD(){
    ofVec2f v = endPt - startPt;
    // Same thing here, only we need to move two-thirds along the line instead of one-third.
    v *= (2/3.0);
    v += startPt;
    return v;
}

ofVec2f KochCurve::KochLine::kochE(){
    return endPt;
}

void KochCurve::KochLine::display() {
    ofLine(startPt.x, startPt.y, endPt.x, endPt.y);
}

