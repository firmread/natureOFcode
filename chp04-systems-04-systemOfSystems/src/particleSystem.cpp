#include "particleSystem.h"

particleSystem::particleSystem(ofPoint location) {
    origin = location;
}

void particleSystem::addParticle(){
    particles.push_back(new particle(origin));
}

void particleSystem::update(){    
    for (int i = 0; i < particles.size(); i++){
        particles[i]->update();
        if(particles[i]->isDead()){
            particles.erase(particles.begin() + i);
        }
    }
}

void particleSystem::display(){
    for (auto& p:particles){
        p->display();
    }
}