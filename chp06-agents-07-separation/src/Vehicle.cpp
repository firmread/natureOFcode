//
//  Vehicle.cpp
//  NOC_6_1_Seek_trail
//
//  Created by Maria Paula Saba on 3/17/13.
//
//

#include "Vehicle.h"


void Vehicle::setup(int x, int y){
    acceleration.set(0, 0);
    velocity.set(0.0, 0.0);
    location.set(x,y);
    
    r = 12;
    maxForce = 0.1;
    topSpeed =3;

}




void Vehicle::applyForce(const ofVec2f & force){
    ofVec2f f(force);
    acceleration += f;
}



void Vehicle::borders(){

    if (location.x < -r) location.x = ofGetWidth()+r;
    if (location.y < -r) location.y = ofGetHeight()+r;
    if (location.x > ofGetWidth()+r) location.x = -r;
    if (location.y > ofGetHeight()+r) location.y = -r;

}


void Vehicle::separate(vector<Vehicle> vehicles){
    
    float desiredseparation = r*2;
    
    ofVec2f sum;
    int count = 0;
    
    vector<Vehicle>::iterator other;
    for (other = vehicles.begin(); other < vehicles.end(); other++){
    
        float d = (location - other->getLocation()).length();

        if((d>0) && (d < desiredseparation)){
         
            ofVec2f diff = location - other->getLocation();
            diff.normalize();
            diff /= d;
            sum+= diff;
            count ++;
            
        }
    }
    
        if(count > 0){
        
            sum /= count;
            sum.normalize();
            sum*=topSpeed;
            
            ofVec2f steer = sum - velocity;
            steer.limit(maxForce);
            
            applyForce(steer);
            
        }
       
        
    

}



void Vehicle::update(){
    velocity += acceleration;
    location += velocity;
    velocity.limit(topSpeed);
    acceleration *= 0;
    
    
    
}

void Vehicle::draw(){
    
   
    
    //float angle = ofRadToDeg(atan2(velocity.y,velocity.x)) + 90;
    
    

    ofPushMatrix();
  
    ofSetColor(175);
    ofFill();
    ofTranslate(location.x, location.y);
    //ofRotate(angle);
    ofEllipse(0, 0, r, r);
    
    ofSetColor(0);
    ofNoFill();
    ofEllipse(0, 0, r, r);
   
    
    ofPopMatrix();


    
}




