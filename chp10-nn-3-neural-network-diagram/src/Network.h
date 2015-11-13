#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

#include "Connection.h"
#include "Neuron.h"
#include "ofMain.h"
#include <vector>

class Network {

private:

    vector<Neuron*> neurons;
    ofVec2f location;


public:

    Network() {};
    Network(float x, float y);
    void addNeuron(Neuron* n);
    void display();
    void connect(Neuron* a, Neuron* b);
    void feedforward(float input);
    void update();

};

#endif // NETWORK_H_INCLUDED
