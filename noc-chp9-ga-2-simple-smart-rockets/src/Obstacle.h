#include "ofMain.h"

#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED

class Obstacle {

public:

    Obstacle() {};
    Obstacle(ofVec2f _location,ofVec2f _dimensions);
    void display();
    bool contains(ofVec2f v);

private:
    ofVec2f location;
    ofVec2f dimensions;

};

#endif // OBSTACLE_H_INCLUDED
