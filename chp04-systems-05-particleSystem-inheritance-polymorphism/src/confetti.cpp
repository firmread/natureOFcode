#include "Confetti.h"

confetti::confetti( ofPoint l ) : particle(l) {}

void confetti::display() {
    ofSetColor( 127, lifespan);
    ofDrawRectangle(location, 12, 12);
    
}

