#include "particleSystem.h"

particleSystem::particleSystem(ofPoint location, ofImage img_) {
    origin = location;
    img = img_;
}

void particleSystem::addParticle(){
    particles.push_back(new particle(origin, img));
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
    for (auto & p : particles){
        p->display();
    }
}