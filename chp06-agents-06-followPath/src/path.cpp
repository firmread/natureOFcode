#include "path.h"

void path::setup(){
    radius = 20;
    points.resize(1);
}


void path::addPoint(float x, float y){

    ofPoint point(x,y);
    points.push_back(point);
    
}


void path::draw(){

    ofSetColor(255,0,0);
    ofNoFill();
   //glLineWidth(radius*2);
    
    ofBeginShape();
    
    for(int v = 0; v < points.size(); v++){
        
    //for(ofPoint v: points){
        ofVertex(points[v].x, points[v].y+20);
    }
    ofEndShape();
    
    
    ofBeginShape();
    
    for(int v = 0; v < points.size(); v++){
        
        //for(ofPoint v: points){
        ofVertex(points[v].x, points[v].y-20);
    }
    ofEndShape();
    
    
    
    ofSetColor(0);
    ofNoFill();
   //glLineWidth(1);
    
    ofBeginShape();
    
    for(int v = 0; v < points.size(); v++){
        
        //for(ofPoint v: points){
        ofVertex(points[v].x, points[v].y);
    }

    ofEndShape();

}