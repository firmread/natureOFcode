#ifndef TARGET_H_INCLUDED
#define TARGET_H_INCLUDED

#include "ofMain.h"

class Target {

public:

    Target();
    void display();
    ofPoint getLocation(){ return location; };

private:

    ofPoint location;

};

#endif // TARGET_H_INCLUDED
