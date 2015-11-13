#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(255,255,255);
    ofSetBackgroundAuto(true);

    network = Network(ofGetWidth()/2,ofGetHeight()/2);
    z =  Neuron(-280,0);
    a =  Neuron(-180,0);
    b =  Neuron(0,100);
    c =  Neuron(0,-100);
    d =  Neuron(180,0);
    e =  Neuron(280,0);

    network.connect(&z,&a);
    network.connect(&a,&b);
    network.connect(&a,&c);
    network.connect(&b,&d);
    network.connect(&c,&d);
    network.connect(&d,&e);

    // Add the Neurons to the network.
    network.addNeuron(&z);
    network.addNeuron(&a);
    network.addNeuron(&b);
    network.addNeuron(&c);
    network.addNeuron(&d);
    network.addNeuron(&e);

    network.feedforward(ofRandom(1));

}

//--------------------------------------------------------------
void ofApp::update()
{
    if (ofGetFrameNum() % 30 == 0)
    {
        //We are choosing to send in an input every 30 frames.
        network.feedforward(ofRandom(1));
    }
    network.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    network.display();
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
