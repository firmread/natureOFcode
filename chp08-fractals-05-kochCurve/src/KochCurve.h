#pragma once
#include "ofMain.h"

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
    
    vector<KochLine> lines;
};
