#include "Perceptron.h"

Perceptron::Perceptron(int n)
{
    for (int i = 0; i < n; i++)
    {
        weights.push_back(ofRandom(-1,1));
    }
}

int Perceptron::feedforward(float inputs[])
{
    float sum = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum += inputs[i]*weights[i];
    }
    return activate(sum);
}


//Output is a +1 or -1.
int Perceptron::activate(float sum)
{
    if (sum > 0) return 1;
    else return -1;
}


//Train the network against known data.
void Perceptron::train(float inputs[], int desired)
{
    int guess = feedforward(inputs);
    float error = desired - guess;
    for (int i = 0; i < weights.size(); i++)
    {
        weights[i] += c * error * inputs[i];
    }
}
