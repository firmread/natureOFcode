//
//  ParticleSystem.cpp
//  NOC_4_03_ParticleSystemClass
//
//  Created by Matthias Esterl on 7/4/13.
//
//

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(ofPoint location) {
    origin = location;
}

void ParticleSystem::addParticle(){
    float r = ofRandom(1);

    if (r < 0.5){
        particles.push_back(new Particle(origin));
    } else {
        particles.push_back(new Confetti(origin));
    }
}

void ParticleSystem::update(){    
    for (int i = 0; i < particles.size(); i++){
        particles.at(i)->update();
        if(particles.at(i)->isDead()){
            cout << "Particle dead!" << endl;
            particles.erase(particles.begin() + i);
        }
    }
}

void ParticleSystem::display(){
    for (int i = 0; i < particles.size(); i++){
        particles.at(i)->display();
    }
}