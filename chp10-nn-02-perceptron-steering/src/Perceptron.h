#ifndef PERCEPTRON_H_INCLUDED
#define PERCEPTRON_H_INCLUDED

#include "ofMain.h"
#include <vector>

class Perceptron {

public:

   Perceptron(int n,float _learnConst);
   Perceptron() {};
   ofPoint feedforward(vector<ofPoint> forces);
   int activate(float sum);
   void train(vector<ofPoint> forces, ofPoint error);
   std::vector<float> weights;

private:

  float learnConst;

};

#endif // PERCEPTRON_H_INCLUDED
