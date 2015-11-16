//
//  Path.cpp
//  NOC_6_6_FollowPath
//
//  Created by Maria Paula Saba on 3/20/13.
//
//

#include "Path.h"

void Path::setup(){
    radius = 20;
    points.resize(1);
}


void Path::addPoint(float x, float y){

    ofVec2f point(x,y);
    points.push_back(point);
    
}


void Path::draw(){

    ofSetColor(255,0,0);
    ofNoFill();
   //glLineWidth(radius*2);
    
    ofBeginShape();
    
    for(int v = 0; v < points.size(); v++){
        
    //for(ofVec2f v: points){
        ofVertex(points[v].x, points[v].y+20);
    }
    ofEndShape();
    
    
    ofBeginShape();
    
    for(int v = 0; v < points.size(); v++){
        
        //for(ofVec2f v: points){
        ofVertex(points[v].x, points[v].y-20);
    }
    ofEndShape();
    
    
    
    ofSetColor(0);
    ofNoFill();
   //glLineWidth(1);
    
    ofBeginShape();
    
    for(int v = 0; v < points.size(); v++){
        
        //for(ofVec2f v: points){
        ofVertex(points[v].x, points[v].y);
    }

    ofEndShape();

}