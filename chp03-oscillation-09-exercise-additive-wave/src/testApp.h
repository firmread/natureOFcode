#pragma once

#include "ofMain.h"


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
    void calcWave();
    void renderWave();

    

    int xspacing, w, maxwaves, theta;
    
    vector <float> amplitude;   // Height of wave
    vector <float> dx;         // Value for incrementing X, to be calculated as a function of period and xspacing
    vector <float> yvalues;     // Using an array to store height values for the wave (not entirely necessary)
    
};
