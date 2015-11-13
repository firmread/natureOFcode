//
//  ParticleSystem.h
//  NOC_4_03_ParticleSystemClass
//
//  Created by Matthias Esterl on 7/4/13.
//
//

#ifndef __NOC_4_03_ParticleSystemClass__ParticleSystem__
#define __NOC_4_03_ParticleSystemClass__ParticleSystem__

#include "ofMain.h"
#include "Particle.h"
#include "Repeller.h"

class ParticleSystem{

    public:
        ParticleSystem(ofPoint);
        void update();
        void display();
        void applyForce(ofPoint);
        void applyRepeller(Repeller);
        void addParticle();
        
        ofPoint origin;
        std::vector<Particle*> particles;
};

#endif /* defined(__NOC_4_03_ParticleSystemClass__ParticleSystem__) */
