#ifndef PERCEPTRON_H_INCLUDED
#define PERCEPTRON_H_INCLUDED

#include "ofMain.h"
#include <vector>

class Perceptron {

public:

   Perceptron(int n);
   Perceptron() {};
   int feedforward(float inputs[]);
   int activate(float sum);
   void train(float inputs[], int desired);

private:

  vector<float> weights;
  float c = 0.01;

};

#endif // PERCEPTRON_H_INCLUDED
