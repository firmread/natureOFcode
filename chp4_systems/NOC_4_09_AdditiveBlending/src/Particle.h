//
//  Particle.h
//  NOC_4_01_SingleParticle
//
//  Created by Matthias Esterl on 7/4/13.
//
//

#ifndef __NOC_4_01_SingleParticle__Particle__
#define __NOC_4_01_SingleParticle__Particle__

#include "ofMain.h"

class Particle{
    public:
        Particle(ofPoint, ofImage);
        void update();
        void display();
        bool isDead();
        
        ofPoint location;
        ofPoint velocity;
        ofPoint acceleration;
        float lifespan;
        ofImage img;
    
};

#endif /* defined(__NOC_4_01_SingleParticle__Particle__) */
