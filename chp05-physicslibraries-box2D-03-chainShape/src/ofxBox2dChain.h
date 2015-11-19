//since ofxBox2d doesn't provide interface with b2chain
//we make one! this one derived from ofxBox2dEdge

#pragma once

#include "ofMain.h"
#include "ofxBox2dBaseShape.h"
#include "ofxBox2dPolygonUtils.h"
#include "ofxBox2dUtils.h"

class ofxBox2dChain : public ofxBox2dBaseShape, public ofPolyline {
    
private:
    bool bFlagShapeUpdate;
    
public:
    
    ofVboMesh mesh;
    void clear(){
        ofPolyline::clear();
        ofxBox2dBaseShape::destroy();
        mesh.clear();
    }
    void destroy(){
        ofPolyline::clear();
        ofxBox2dBaseShape::destroy();
        mesh.clear();
    }
    
    void create(b2World * b2dworld){
        bFlagShapeUpdate = false;
        
        if(size() < 2) {
            printf("need at least 3 points\n");
            return;
        }
        
        if (body != NULL) {
            b2dworld->DestroyBody(body);
            body = NULL;
        }
        
        // create the body from the world (1)
        b2BodyDef		bd;
        bd.type			= density <= 0.0 ? b2_staticBody : b2_dynamicBody;
        body			= b2dworld->CreateBody(&bd);
        
        // with some help from http://stackoverflow.com/questions/6829133/box2d-variable-length-array-of-non-pod-element-type-b2vec2
        
        b2ChainShape chain;
        vector<ofPoint>&pts = ofPolyline::getVertices();
        b2Vec2 *vertices = new b2Vec2[(int)size()];
        for(int i=0; i<(int)size(); i++) {
            vertices[i].Set(screenPtToWorldPt(pts[i]).x, screenPtToWorldPt(pts[i]).y);
        }
//        vector<b2Vec2> vertices;
//        for(int i=0; i<(int)size(); i++) {
//            vertices.push_back(b2Vec2(screenPtToWorldPt(pts[i])));
//        }
        chain.CreateChain(vertices, size());
        body->CreateFixture(&chain, density);
        
        
        mesh.clear();
        mesh.setUsage(body->GetType()==b2_staticBody?GL_STATIC_DRAW:GL_DYNAMIC_DRAW);
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
        
        /// OF_PRIMITIVE_TRIANGLES, OF_PRIMITIVE_TRIANGLE_STRIP,
        /// OF_PRIMITIVE_TRIANGLE_FAN, OF_PRIMITIVE_LINES, OF_PRIMITIVE_LINE_STRIP,
        /// OF_PRIMITIVE_LINE_LOOP, OF_PRIMITIVE_POINTS.
        
        for(int i=0; i<(int)size(); i++) {
            mesh.addVertex(ofVec3f(pts[i].x, pts[i].y));
        }
        
        flagHasChanged();
        alive = true;
    }
    
    
    void addVertexes(ofPolyline &polyline){
        
        for (int i=0; i<polyline.size(); i++) {
            ofPolyline::addVertex(polyline[i].x, polyline[i].y);
        }
        flagHasChanged();
        
    }
    
    void addVertexes(vector <ofVec2f> &pts){
        
        for (int i=0; i<pts.size(); i++) {
            ofPolyline::addVertex(pts[i].x, pts[i].y);
        }
        flagHasChanged();
        
    }
    
    
    void updateShape(){
        if(body==NULL) return;
        // const b2Transform& xf = body->GetTransform();
        ofPolyline::clear();
        mesh.clear();
        mesh.setUsage(body->GetType()==b2_staticBody?GL_STATIC_DRAW:GL_DYNAMIC_DRAW);
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
        
        for (b2Fixture * f = body->GetFixtureList(); f; f = f->GetNext()) {
            b2EdgeShape * edge = (b2EdgeShape*)f->GetShape();
            
            if(edge) {
                ofPolyline::addVertex(worldPtToscreenPt(edge->m_vertex2));
                ofPolyline::addVertex(worldPtToscreenPt(edge->m_vertex1));
                
                mesh.addVertex(ofVec3f(worldPtToscreenPt(edge->m_vertex2)));
                mesh.addVertex(ofVec3f(worldPtToscreenPt(edge->m_vertex1)));
            }
        }
        
        bFlagShapeUpdate = true;
        flagHasChanged();
    }
    
    void draw(){
        if(body==NULL) return;
        
        if(!bFlagShapeUpdate && body->GetType() != b2_staticBody) {
            printf("Need to update shape first\n");
        }
        // Temporary fix until we switch to OF 0.8.0.
        mesh.draw();
        //ofPolyline::draw();
        bFlagShapeUpdate = false;
    }
};