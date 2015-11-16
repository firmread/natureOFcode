#ifndef PERCEPTRON_H_INCLUDED
#define PERCEPTRON_H_INCLUDED

#include "ofMain.h"
#include <vector>

class Perceptron {

public:

   Perceptron(int n,float _learnConst);
   Perceptron() {};
   ofVec2f feedforward(vector<ofVec2f> forces);
   int activate(float sum);
   void train(vector<ofVec2f> forces, ofVec2f error);
   std::vector<float> weights;

private:

  float learnConst;

};

#endif // PERCEPTRON_H_INCLUDED
