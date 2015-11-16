
#include "ofMain.h"

class mover{
public:
    mover();
    void update();
    void display();
    void checkEdges();
    
    ofPoint location;
    ofPoint velocity;
    
};
