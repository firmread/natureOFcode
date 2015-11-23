//
//  Rule.h
//  04_Lsystem
//
//  Created by Charlie Whitney on 11/19/13.
//
//

#pragma once

#include "ofMain.h"

class Rule {
public:
    Rule( char _a, string _b){
        a = _a;
        b = _b;
    };
   
    char a;
    string b;
};