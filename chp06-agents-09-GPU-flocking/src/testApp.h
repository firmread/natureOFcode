#pragma once

#include "ofMain.h"
#include "pingPongBuffer.h"

class testApp : public ofBaseApp{

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
    
        // shaders
        ofShader velocity;
        ofShader position;
        ofShader render;
    
        // fbo you're rendering to
        ofFbo    renderFBO;
    
        // ping-pong buffers for position and velocity
        pingPongBuffer posPingPong;
        pingPongBuffer velPingPong;
    
        // parameters for flocking
        float maxVelocity;
        float maxForce;
        float desiredSeparation;
        float neighborDistance;
    
        // size of circles
        float particleSize;
    
        // mesh for position + color store
        ofMesh mesh;
};
