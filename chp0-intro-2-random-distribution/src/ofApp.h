#pragma once
#include "ofMain.h"

#define ARRAYSIZE 50

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void reset();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    int boxWidth;
    int speed;
    int randomCounts[ARRAYSIZE];

};
