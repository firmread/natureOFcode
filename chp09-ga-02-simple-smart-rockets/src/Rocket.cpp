#include "Rocket.h"

Rocket::Rocket(float lifetime)
{
    dna = DNA(lifetime);
    location = ofPoint(ofGetWidth()/2,ofGetHeight());
    velocity = ofPoint(0,0);
    acceleration = ofPoint(0,0);
}

Rocket::Rocket()
{
    location = ofPoint(ofGetWidth()/2,ofGetHeight());
    velocity = ofPoint(0,0);
    acceleration = ofPoint(0,0);
}

void Rocket::applyForce(ofPoint f)
{
    acceleration += f;
}

void Rocket::display()
{
    float theta = velocity.angle(ofPoint(0,1));
    ofFill();
    ofPushMatrix();
    ofTranslate(location.x,location.y);
    ofRotate(-theta);

    ofSetColor(0,0,0,175);
    ofBeginShape();
    ofVertex(0, r*2);
    ofVertex(-r, -r*2);
    ofVertex(r, -r*2);
    ofEndShape();

    ofPopMatrix();
}

Rocket Rocket::mate(Rocket partner)
{
    Rocket child = Rocket();
    child.setDNA(dna.crossover(partner.getDNA()));
    child.setTarget(target);
    child.setObstacles(obstacles);
    return child;
}

void Rocket::update()
{
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
}


void Rocket::checkObstacles() {
    for (int i = 0; i< obstacles.size(); i++) {
      if (obstacles[i].contains(location)) {
        stopped = true;
      }
    }
}

void Rocket::run()
{
    // would be slightly more efficient to check for obstacles after checking if hit target
    checkObstacles();
    if(location.distance(target) > 10 && !stopped)
    {
        vector<ofPoint> genes = dna.getGenes();
        // Apply a force from the genes array.
        applyForce(genes[geneCounter]);
        // Go to the next force in the genes array.
        geneCounter++;
        //Update the Rocket’s physics.
        update();
    }
}

float Rocket::calcFitness()
{
    /*
    int score = 0;
    for (int i = 0; i < genesSize; i++)   {}
    */
    float d = location.distance(target);
    //Squaring 1 divided by distance
    if(d == 0)
    {
        d = 0.1;
    }
    fitness = pow(1/d,2);
    if(stopped) fitness *= 0.01;
    return fitness;
}
