#include <vector>
#include "ofMain.h"

#ifndef KOCHCURVE_H_INCLUDED
#define KOCHCURVE_H_INCLUDED

class KochCurve {

public:

    KochCurve(){};
    KochCurve(ofVec2f a, ofVec2f b,int iterations);
    void display();
    void generateLines();


private:

    class KochLine {

        public:

        KochLine() {};
        KochLine(ofVec2f a, ofVec2f b);
        void display();

        ofVec2f kochA();
        ofVec2f kochB();
        ofVec2f kochC();
        ofVec2f kochD();
        ofVec2f kochE();

        private:

        ofVec2f startPt;
        ofVec2f endPt;

    };
    std::vector<KochLine> lines;

};

#endif // KOCHCURVE_H_INCLUDED
