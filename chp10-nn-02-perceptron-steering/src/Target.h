#ifndef TARGET_H_INCLUDED
#define TARGET_H_INCLUDED

#include "ofMain.h"

class Target {

public:

    Target();
    void display();
    ofVec2f getLocation(){ return location; };

private:

    ofVec2f location;

};

#endif // TARGET_H_INCLUDED
