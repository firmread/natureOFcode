// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// An LSystem has a starting sentence
// An a ruleset
// Each generation recursively replaces characteres in the sentence
// Based on the ruleset

// OF port by Brett Renfer
// http://www.robotconscience.com

#pragma once

#include "Rule.h"

class LSystem
{
public:
    
    // Construct an LSystem with a startin sentence and a ruleset
    LSystem(string axiom, vector<Rule* > r) {
        sentence = axiom;
        ruleset.clear();
        ruleset.swap(r);
        generation = 0;
    }
    
    // Generate the next generation
    void generate() {
        // empty string
        // strings in C++ are not immutable like java
        // so we can just += instead of append
        string nextgen = "";
        // For every character in the sentence
        for (int i = 0; i < sentence.length(); i++) {
            // What is the character
            char curr = sentence.at(i);
            // We will replace it with itself unless it matches one of our rules
            string replace = ofToString(curr);
            // Check every rule
            for (int j = 0; j < ruleset.size(); j++) {
                char a = ruleset[j]->getA();
                // if we match the Rule, get the replacement String out of the Rule
                if (a == curr) {
                    replace = ruleset[j]->getB();
                    break;
                }
            }
            // Append replacement String
            nextgen += replace;
        }
        // Replace sentence
        sentence = nextgen;
        // Increment generation
        generation++;
    }
    
    string getSentence() {
        return sentence;
    }
    
    int getGeneration() {
        return generation;
    }
    
protected:
    
    
    string sentence;        // The sentence (a String)
    vector<Rule*> ruleset;   // The ruleset (a vector of Rule objects)
    int generation;         // Keeping track of the generation #
    
};




