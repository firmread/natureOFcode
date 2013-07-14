//
//  GOL.h
//  NOC_7_02_GameOfLifeSimple
//
//  Created by Matthias Esterl on 7/5/13.
//
//

#ifndef __NOC_7_02_GameOfLifeSimple__GOL__
#define __NOC_7_02_GameOfLifeSimple__GOL__

#include "ofMain.h"
#include "GOLCell.h"

class GOL{
    public:
        GOL();
        void init();
        void generate();
        void display();
    
        int w ;
        int columns;
        int rows;
        vector< vector<GOLCell*> > board;
};

#endif /* defined(__NOC_7_02_GameOfLifeSimple__GOL__) */
