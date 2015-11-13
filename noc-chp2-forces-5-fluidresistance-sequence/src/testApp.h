#pragma once

#include "ofMain.h"
#include "Mover.h"
#include "Liquid.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    void reset();

    vector <Mover> movers;
    Liquid* liquid;
    ofVec2f acceleration, location, gravity;
    ofImage 			img;
    int snapCounter;
    char 				snapString[255];
};
