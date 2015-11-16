#include "Neuron.h"

#include <iostream>

Neuron::Neuron(float x, float y)
{
    location = ofVec2f(x,y);
}

void Neuron::display()
{
    for (int i = 0; i < connections.size(); i++)
    {
        connections[i].display();
    }
    float radiusInc = 0;
    if(fireFrame>0){
        radiusInc = sin(fireFrame * 0.1) * 10;
        if(radiusInc<0){
            radiusInc = 0;
            fireFrame = 0;
        } else {
            fireFrame++;
        }
    }
    ofNoFill();
    ofSetColor(0,0,0);
    ofSetLineWidth(2);
    ofCircle(location.x,location.y,16 + radiusInc);
    ofFill();
    ofSetColor(0,0,0,ofMap(sum,0,1.0,0,255));
    ofCircle(location.x,location.y,15 + radiusInc);
}

void Neuron::addConnection(Connection c)
{
    connections.push_back(c);
    //std::cout << "Connections: " << connections.size() << std::endl;
}

void Neuron::feedforward(float input)
{
    sum += input;
    std::cout << "Neuron Feed Forward: " << sum << std::endl;
    //Activate the neuron and fire the outputs?
    if (sum > 1)
    {
        fire();
        //If we’ve fired off our output, we can reset our sum to 0.
        sum = 0;
    }
}

void Neuron::fire()
{
   fireFrame = 1;
   std::cout << "Neuron Fire" << std::endl;
   for (int i = 0; i < connections.size(); i++) {
    //The Neuron sends the sum out through all of its connections
      connections[i].feedforward(sum);
    }
}

void Neuron::update(){
   for (int i = 0; i < connections.size(); i++) {
      connections[i].update();
    }
}
