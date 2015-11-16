#include "Perceptron.h"
#include <iostream>

Perceptron::Perceptron(int n, float _learnConst)
{
    weights.clear();
    std::cout << "weight count: " << n << std::endl;
    learnConst = _learnConst;
    for (int i = 0; i < n; i++)
    {
        weights.push_back(ofRandom(-1,1));
    }
    std::cout << "weight count added: " << weights.size() << std::endl;

}

ofVec2f Perceptron::feedforward(vector<ofVec2f> forces)
{
    std::cout << "weight count: " << weights.size() << " learn const: " << learnConst << std::endl;
    ofVec2f sum = ofVec2f(0,0);

    for (int i = 0; i < weights.size(); i++)
    {
        sum += forces[i]*weights[i];
        ofDrawBitmapString("F: " + ofToString(forces[i],4), 20, 20 + (i*30) );
    }

    return sum;
}

//Output is a +1 or -1.
int Perceptron::activate(float sum)
{
    if (sum > 0) return 1;
    else return -1;
}

//Train the network against known data.
void Perceptron::train(vector<ofVec2f> forces, ofVec2f error)
{

    for (int i = 0; i < weights.size(); i++)
    {
       weights[i] += learnConst * error.x * forces[i].x;
       weights[i] += learnConst * error.y * forces[i].y;
    }
}
