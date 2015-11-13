
#include "walker.h"

walker::walker() {
    x = 0;
    y = 0;
    scale = 5;
}


void walker::update() {
    int choice = int(ofRandom(4));
    cout << choice << endl;
    
    if (choice == 0) x++;
    else if (choice == 1) x--;
    else if (choice == 2) y++;
    else if (choice == 3) y--;
    
    int rangeWidth = (ofGetWidth()/2) /scale;
    int rangeHeight = (ofGetHeight()/2) /scale;
    
    x = constrain(x, -rangeWidth, rangeWidth);
    y = constrain(y, -rangeHeight, rangeHeight);
}


void walker::draw() {
    ofSetColor(0,20);
    ofDrawRectangle(x, y, 1, 1);
}


int walker::constrain(int input, int min, int max) {
    return (input < min) ? min : ((input > max) ? max : input);
}