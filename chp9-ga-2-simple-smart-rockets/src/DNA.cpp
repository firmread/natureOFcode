#include "DNA.h"

DNA::DNA(float _lifetime)
{
  lifetime = _lifetime;
  for (int i = 0; i < lifetime; i++) {
      genes.push_back(randomDirection() * ofRandom(maxforce));
  }
}

DNA DNA::crossover(DNA partner){
    DNA child = DNA();
    // Picking a random “midpoint” in the genes array
    int midpoint = ofRandom(genes.size());
    for (int i = 0; i < genes.size(); i++) {
      // Before midpoint copy genes from one parent, after midpoint copy genes from the other parent
      if (i>midpoint) child.addGene(genes[i]);
      else child.addGene(partner.genes[i]);
    }
    //Return the new child DNA
    return child;
}

void DNA::addGene(ofVec2f gene){
    genes.push_back(gene);
}

void DNA::mutate(float mutationRate) {
    for (int i = 0; i < genes.size(); i++) {
      if (ofRandom(1) < mutationRate) {

        genes[i] = (randomDirection() * ofRandom(maxforce));

      }
    }
}

ofVec2f DNA::randomDirection() {
    double pi = 3.1415926535897;
    float angleRads = ofRandom(2.0 * pi);
    return ofVec2f(cos(angleRads),sin(angleRads));
}
