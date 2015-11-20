#include "CA.h"
CA::CA(){
    w=5;
    restart();
}


// Make a random ruleset
void CA::randomize(){
    for (int i = 0; i < 8; i++){
        ruleset[i] = int(ofRandom(2));
    }
}


// Reset to generation 0
void CA::restart(){
    int a = 0;
    for (int i = 0; i<ofGetWidth()/w; i++) {
        cells.push_back(a);
    }
    
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
// This is the concise conversion to binary way
/*int rules (int a, int b, int c) {
 String s = "" + a + b + c;
 int index = Integer.parseInt(s, 2);
 return ruleset[index];
 }*/
// For JavaScript Mode

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


// The CA is done if it reaches the bottom of the screen
bool CA::finished() {
//    if (generation > ofGetHeight()/w) {
    if (generation > 200/w) {
        return true;
    }
    else {
        return false;
    }
}








