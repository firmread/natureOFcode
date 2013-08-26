//
//  Walker.cpp
//  NOC_I_1_RandomWalkTraditional
//
//  Created by Matthias Esterl on 7/7/13.
//  http://madcity.at
//

#include "Walker.h"

Walker::Walker() {
    x = ofGetWindowWidth()/2;
    y = ofGetWindowHeight()/2;
}

void Walker::render() {
    ofSetColor(0);
    
    ofRect(x, y, 1, 1);
}

void Walker::step() {
    int choice = int(ofRandom(4));
    
    if (choice == 0) {
        x++;
    } else if (choice == 1) {
        x--;
    } else if (choice == 2) {
        y++;
    } else {
        y--;
    }
    
    x = constrain(x, 0, ofGetWindowWidth()-1);
    y = constrain(y, 0, ofGetWindowHeight()-1);
}

int Walker::constrain(int amt, int low, int high) {
    /* http://forum.openframeworks.cc/index.php?topic=1413.0 */
    
    return (amt < low) ? low : ((amt > high) ? high : amt);
}