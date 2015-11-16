
#include "walker.h"

walker::walker() {
    x = 0;
    y = 0;
    scale = 5;
}


void walker::update() {
    float choice = ofRandom(1);
    cout << choice << endl;
    
    if (choice < 0.4) x++;
    else if (choice < 0.6) x--;
    else if (choice < 0.8) y++;
    else y--;
    
    int rangeWidth = (ofGetWidth()/2) /scale;
    int rangeHeight = (ofGetHeight()/2) /scale;
    
    x = overflow(x, -rangeWidth, rangeWidth);
    y = constrain(y, -rangeHeight, rangeHeight);
}


void walker::draw() {
    ofSetColor(0,20);
    ofDrawRectangle(x, y, 1, 1);
}


int walker::constrain(int input, int min, int max) {
    return (input < min) ? min : ((input > max) ? max : input);
}


int walker::overflow(int input, int min, int max) {
    return (input < min) ? max : ((input > max) ? min : input);
}