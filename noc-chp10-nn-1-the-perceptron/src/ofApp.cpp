#include "ofApp.h"

//The formula for a line

float f(float x)
{
    return 2*x+1;
}


//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(255,255,255);
    ofSetBackgroundAuto(true);

    ptron = Perceptron(3);


    //Make 2,000 training points.
    for (int i = 0; i < TrainingCount; i++)
    {
        float x = ofRandom(-ofGetWidth()/2,ofGetWidth()/2);
        float y = ofRandom(-ofGetHeight()/2,ofGetHeight()/2);

        //Is the correct answer 1 or -1?
        int answer = 1;
        if (y < f(x)) answer = -1;

        training.push_back(Trainer(x, y, answer));
    }
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{

    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);

    ptron.train(training[tCount].getInputs(), training[tCount].getAnswer());

    // For animation, we are training one point at a time.

    tCount = (tCount + 1) % training.size();

    for (int i = 0; i < tCount; i++)
    {
        // stroke(0);


        float* inputs = training[i].getInputs();


        int guess = ptron.feedforward(inputs);

        // Show the classification—white for -1, grey for +1.

        ofSetColor(0,0,0);
        ofCircle(inputs[0],inputs[1], 10);

        if (guess > 0)
            ofSetColor(127,127,127);
        else
            ofSetColor(255,255,255);

        ofCircle(inputs[0], inputs[1], 8);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
