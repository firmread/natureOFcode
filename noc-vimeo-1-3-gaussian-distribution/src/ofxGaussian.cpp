//
//  ofxGaussian.cpp
//  1_3_Gaussian_Distribution
//
//  Created by Firm Read on 6/28/13.
//
//

#include "ofxGaussian.h"

bool haveNextNextGaussian = false;
float nextNextGaussian;

float ofxGaussian() {
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        
        return v1 * multiplier;
    }
}