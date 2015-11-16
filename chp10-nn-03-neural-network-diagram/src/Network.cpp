#include "Network.h"

Network::Network(float x, float y)
{
    location = ofVec2f(x,y);
}

void Network::addNeuron(Neuron* n)
{
    neurons.push_back(n);
}

void Network::display()
{
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    for (int i = i; i < neurons.size(); i++)
    {
        neurons[i]->display();
    }
    ofPopMatrix();
}

void Network::connect(Neuron* a, Neuron* b)
{
    // Connection has a random weight.
    Connection c = Connection(a, b, ofRandom(1.0));
    a->addConnection(c);
}

void Network::feedforward(float input) {
    Neuron* start = neurons[0];
    start->feedforward(input);
}

void Network::update(){
    for (int i = i; i < neurons.size(); i++)
    {
        neurons[i]->update();
    }
}
