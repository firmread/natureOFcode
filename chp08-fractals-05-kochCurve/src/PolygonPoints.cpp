#include <vector>
#include "ofMain.h"

#include "PolygonPoints.h"

PolygonPoints::PolygonPoints(int sidesInit,ofVec2f centInit, float sideLengthInit) {
    sides = sidesInit;
    center = centInit;
    sideLength = sideLengthInit;

    float sumIntAngles = (sides-2) * 180.0;         // formula for getting sum of internal angles in a poly (n-2) x 180
    float intAngleSides = sumIntAngles / sides;     // angle between each pair of sides, divide total by number of sides
    float intAngleCenter = 180.0 - intAngleSides;   // internal angle between lines from center to points on edge, each int triangle has 2 angles which are half angle between sides, take them away from sum of int angles in a triangle
    distCentToPoint = sideLength / (2 * sin(ofDegToRad(intAngleCenter/2)) );
    ofVec2f radiusVec = ofVec2f(0,distCentToPoint);

    for(int i = 0; i < sides; i++) {
        ofVec2f p = radiusVec;
        p.rotate(i * intAngleCenter);
        p += center;
        points.push_back(p);
    }

}

void PolygonPoints::display(bool showLines, bool showPoints){
    ofSetColor(0,0,0);

    for(int i = 0; i < sides; i++) {
        if(showPoints) ofCircle(points[i].x,points[i].y,5);
        if(showLines) {
                int nextPointPos = (i<sides-1)?i+1:0;
                ofLine(points[i].x,points[i].y,points[nextPointPos].x,points[nextPointPos].y);
        }
    }
    // ofLine(center.x,center.y,points[0].x,points[0].y);
}

vector<ofVec2f> PolygonPoints::getPoints() {
    return points;
}

float PolygonPoints::getDistCentToPoint() {
    return distCentToPoint;
}

