#include "particleSystem.h"

particleSystem::particleSystem(ofPoint location) {
    origin = location;
}

void particleSystem::addParticle(){
    float r = ofRandom(1);

    if (r < 0.5){
        particles.push_back(new particle(origin));
    } else {
        particles.push_back(new confetti(origin));
    }
}

void particleSystem::update(){    
    for (int i = 0; i < particles.size(); i++){
        particles.at(i)->update();
        if(particles.at(i)->isDead()){
            particles.erase(particles.begin() + i);
        }
    }
}

void particleSystem::display(){
    for (auto &p:particles){
        p->display();
    }
}