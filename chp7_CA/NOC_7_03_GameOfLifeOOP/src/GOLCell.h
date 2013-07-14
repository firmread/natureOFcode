//
//  Cell.h
//  NOC_7_03_GameOfLifeOOP
//
//  Created by Matthias Esterl on 7/5/13.
//
//

#ifndef __NOC_7_03_GameOfLifeOOP__Cell__
#define __NOC_7_03_GameOfLifeOOP__Cell__

#include "ofMain.h"

class GOLCell{
    public:
        GOLCell(float, float, float);
    	void display();
        void newState(int);
        void savePrevious();
        
    
        float x;
        float y;
        float w;
    
        int state;
        int previous;
};

#endif /* defined(__NOC_7_03_GameOfLifeOOP__Cell__) */
