//
//  Confetti.h
//  NOC_4_05_ParticleSystemInheritancePolymorphism
//
//  Created by Matthias Esterl on 7/4/13.
//
//

#ifndef __NOC_4_05_ParticleSystemInheritancePolymorphism__Confetti__
#define __NOC_4_05_ParticleSystemInheritancePolymorphism__Confetti__

#include "Particle.h"

class Confetti : public Particle {
    public:
        Confetti(ofPoint);
        void display();
};

#endif /* defined(__NOC_4_05_ParticleSystemInheritancePolymorphism__Confetti__) */
