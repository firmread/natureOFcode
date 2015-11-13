#include "Trainer.h"

 Trainer::Trainer(float x, float y, int a) {
    inputs[0] = x;
    inputs[1] = y;

    //Note that the Trainer has the bias input built into its array.
    inputs[2] = 1;
    answer = a;
  }
