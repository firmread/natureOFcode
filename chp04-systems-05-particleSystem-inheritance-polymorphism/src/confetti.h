#pragma once
#include "particle.h"

class confetti : public particle {
public:
    confetti(ofPoint);
    void display();
};
