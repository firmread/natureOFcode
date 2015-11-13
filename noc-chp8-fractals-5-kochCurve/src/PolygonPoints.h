#include <vector>
#include "ofMain.h"

#ifndef POLYGONPOINTS_H_INCLUDED
#define POLYGONPOINTS_H_INCLUDED

class PolygonPoints {

public:

    PolygonPoints() {};
    PolygonPoints(int sidesInit, ofVec2f centInit,float sideLengthInit);
    vector<ofVec2f> getPoints();
    float getDistCentToPoint();
    void display(bool showLines, bool showPoints);

private:

    float distCentToPoint;
    int sides;
    float sideLength;
    ofVec2f center;
    vector<ofVec2f> points;

};

#endif // POLYGONPOINTS_H_INCLUDED
