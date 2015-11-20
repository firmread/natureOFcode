
#include "CA.h"
CA::CA(){
    w = 10;
    int cellNoX = ofGetWidth()/w;
    int temp[cellNoX];
    
    for (int i =0; i<cellNoX; i++) {
        temp[i] = 0;
    }
    vector<int>tempV(temp, temp+cellNoX);
    cells = tempV;
    
    // We arbitrarily start with just the middle cell having a state of "1"
    cells[cells.size()/2] = 1;
    generation = 0;
    
}



// The process of creating the new generation
void CA::generate(){
    // First we create an empty array for the new values
    int nextgen[cells.size()];
    // For every spot, determine new state by examing current state, and neighbor states
    // Ignore edges that only have one neighor
    for (int i = 1 ; i< cells.size()-1; i++) {
        int left = cells[i-1];    // Left neighbor state
        int me = cells[i];        // Current state
        int right = cells[i+1];   // Right neighbor state
        
        nextgen[i] = rules(left, me, right);
        // Compute next generation state based on ruleset
    }
    vector<int>nextgenV(nextgen, nextgen+cells.size());
    
    cells = nextgenV;
    generation++;
    
}




// This is the easy part, just draw the cells, fill 255 for '1', fill 0 for '0'
void CA::display(){
    for (int i =0; i<cells.size(); i++) {
        if (cells[i] == 1) ofSetColor(0);
        else               ofSetColor(255);
        ofDrawRectangle(i*w, generation*w, w, w);
    }
}




// Implementing the Wolfram rules
// Could be improved and made more concise, but here we can explicitly see what is going on for each case

int CA::rules (int a, int b, int c) {
    if (a == 1 && b == 1 && c == 1) return ruleset[0];
    if (a == 1 && b == 1 && c == 0) return ruleset[1];
    if (a == 1 && b == 0 && c == 1) return ruleset[2];
    if (a == 1 && b == 0 && c == 0) return ruleset[3];
    if (a == 0 && b == 1 && c == 1) return ruleset[4];
    if (a == 0 && b == 1 && c == 0) return ruleset[5];
    if (a == 0 && b == 0 && c == 1) return ruleset[6];
    if (a == 0 && b == 0 && c == 0) return ruleset[7];
    return 0;
}



