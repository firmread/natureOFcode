#pragma once

#include "ofMain.h"
#include "Walker.h"

class ofApp : public ofBaseApp {
  private:
    ofColor m_backgroundColor { 40, 44, 52 };
    ofColor m_walkerColor { 140, 132, 247 };

    Walker m_walker;

  public:

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
};
