//
//  Walker.h
//  NOC_I_1_RandomWalkTraditional
//
//  Created by Matthias Esterl on 7/7/13.
//  http://madcity.at
//

#ifndef __NOC_I_1_RandomWalkTraditional__Walker__
#define __NOC_I_1_RandomWalkTraditional__Walker__

#include "ofMain.h"

class Walker {
    public:
        Walker();
        void display();
        void walk();
        int constrain(int, int, int);

        ofPoint location;
        ofPoint noff;
};

#endif /* defined(__NOC_I_1_RandomWalkTraditional__Walker__) */
