//
//  Repeller.h
//  NOC_4_07_ParticleSystemForcesRepeller
//
//  Created by Matthias Esterl on 7/5/13.
//
//

#ifndef __NOC_4_07_ParticleSystemForcesRepeller__Repeller__
#define __NOC_4_07_ParticleSystemForcesRepeller__Repeller__

#include "ofMain.h"
#include "Particle.h"

class Repeller{
public:
    Repeller(ofPoint);
    void display();
    ofPoint repel(Particle);
    
    ofPoint location;
};

#endif /* defined(__NOC_4_07_ParticleSystemForcesRepeller__Repeller__) */
