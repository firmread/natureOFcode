//
//  LSystem.cpp
//  04_Lsystem
//
//  Created by Charlie Whitney on 11/19/13.
//
//

#include "LSystem.h"

void LSystem::setup(string axiom, vector<Rule> rules){
    sentence = axiom;
    ruleList = rules;
}

void LSystem::addGeneration() {
    string nextGen = "";
    
    for( int i=0; i<sentence.length(); i++ ){
        char cur = sentence[i];
        
        string replacement = ofToString(cur);
        
        for( int k=0; k<ruleList.size(); k++){
            if( ruleList[k].a == cur ){
                replacement = ruleList[k].b;
                break;
            }
        }
        
        nextGen += replacement;
        
    }
    sentence = nextGen;
    generation++;
}