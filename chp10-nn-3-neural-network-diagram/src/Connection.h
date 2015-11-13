#ifndef CONNECTION_H_INCLUDED
#define CONNECTION_H_INCLUDED

class Neuron;

#include "Neuron.h"
#include "ofMain.h"

class Connection {

private:

    Neuron* a;
    Neuron* b;
    float weight;

    bool sending = false;
    ofVec2f sender;
    float output;

public:

    Connection() {};
    Connection(Neuron* from, Neuron* to,float w);
    void display();
    void feedforward(float val);
    void update();

};

#endif // CONNECTION_H_INCLUDED
