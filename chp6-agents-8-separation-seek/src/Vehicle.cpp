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


ofVec2f Vehicle::seek(const ofVec2f & target){
    ofVec2f desired;
    desired = target - location;
    
    desired.normalize();
    desired*=topSpeed;
    
    ofVec2f steer;
    steer = desired - velocity;
    steer.limit(maxForce);
    
    return steer;
    
}


ofVec2f Vehicle::separate(vector<Vehicle> vehicles){
    
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
            
            sum -= velocity;
            sum.limit(maxForce);
            
            
        }
       
    return sum;
    

}

void Vehicle::applyBehaviours(vector<Vehicle> vehicles){

    ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
    
    ofVec2f separateForce = separate(vehicles);
    ofVec2f seekForce = seek(mouse);
    
    
    separateForce*=2;
    seekForce *= 1;
    
    applyForce(separateForce);
    applyForce(seekForce);
    


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




