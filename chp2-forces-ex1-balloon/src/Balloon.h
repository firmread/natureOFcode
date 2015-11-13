#include "ofMain.h"
#include "ofApp.h"

#ifndef BALLOON_H_INCLUDED
#define BALLOON_H_INCLUDED

class Balloon {

public:
    Balloon();
    void display();
    void update();
    void checkEdges();
    void applyForce(ofVec2f);
    void setPosition(int,int);

private:

    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;

};

#endif // BALLOON_H_INCLUDED
