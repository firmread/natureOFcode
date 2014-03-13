
#include "ofMain.h"

class mover{
public:
    void setup();
    void update();
    void display();
    void checkEdges();
    
    ofPoint location;
    ofPoint velocity;
    
};
