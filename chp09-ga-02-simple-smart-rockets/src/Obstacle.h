#include "ofMain.h"

#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED

class Obstacle {

public:

    Obstacle() {};
    Obstacle(ofPoint _location,ofPoint _dimensions);
    void display();
    bool contains(ofPoint v);

private:
    ofPoint location;
    ofPoint dimensions;

};

#endif // OBSTACLE_H_INCLUDED
