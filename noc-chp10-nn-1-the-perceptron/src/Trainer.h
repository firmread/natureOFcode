#ifndef TRAINER_H_INCLUDED
#define TRAINER_H_INCLUDED

#include "ofMain.h"

class Trainer {

private:

  float inputs[3];
  int answer;

public:

  Trainer(float x, float y, int a);
  float* getInputs() { return inputs; };
  int getAnswer() { return answer; };

};

#endif // TRAINER_H_INCLUDED
