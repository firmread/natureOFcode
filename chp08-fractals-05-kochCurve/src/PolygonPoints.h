#include <vector>
#include "ofMain.h"

#ifndef POLYGONPOINTS_H_INCLUDED
#define POLYGONPOINTS_H_INCLUDED

class PolygonPoints {

public:

    PolygonPoints() {};
    PolygonPoints(int sidesInit, ofPoint centInit,float sideLengthInit);
    vector<ofPoint> getPoints();
    float getDistCentToPoint();
    void display(bool showLines, bool showPoints);

private:

    float distCentToPoint;
    int sides;
    float sideLength;
    ofPoint center;
    vector<ofPoint> points;

};

#endif // POLYGONPOINTS_H_INCLUDED
