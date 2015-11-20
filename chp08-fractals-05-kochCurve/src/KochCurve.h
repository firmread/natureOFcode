#include <vector>
#include "ofMain.h"

#ifndef KOCHCURVE_H_INCLUDED
#define KOCHCURVE_H_INCLUDED

class KochCurve {

public:

    KochCurve(){};
    KochCurve(ofPoint a, ofPoint b,int iterations);
    void display();
    void generateLines();


private:

    class KochLine {

        public:

        KochLine() {};
        KochLine(ofPoint a, ofPoint b);
        void display();

        ofPoint kochA();
        ofPoint kochB();
        ofPoint kochC();
        ofPoint kochD();
        ofPoint kochE();

        private:

        ofPoint startPt;
        ofPoint endPt;

    };
    std::vector<KochLine> lines;

};

#endif // KOCHCURVE_H_INCLUDED
