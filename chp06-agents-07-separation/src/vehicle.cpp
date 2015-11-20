#include "vehicle.h"

void vehicle::setup(int x, int y){
    acceleration.set(0, 0);
    velocity.set(0.0, 0.0);
    location.set(x,y);
    
    r = 12;
    maxForce = 0.1;
    topSpeed =3;

}

void vehicle::applyForce(const ofPoint & force){
    ofPoint f(force);
    acceleration += f;
}

void vehicle::borders(){

    if (location.x < -r) location.x = ofGetWidth()+r;
    if (location.y < -r) location.y = ofGetHeight()+r;
    if (location.x > ofGetWidth()+r) location.x = -r;
    if (location.y > ofGetHeight()+r) location.y = -r;
}

void vehicle::separate(vector<vehicle> vehicles){
    
    float desiredseparation = r*2;
    
    ofPoint sum;
    int count = 0;
    
    vector<vehicle>::iterator other;
    for (other = vehicles.begin(); other < vehicles.end(); other++){
    
        float d = (location - other->getLocation()).length();

        if((d>0) && (d < desiredseparation)){
         
            ofPoint diff = location - other->getLocation();
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
            
            ofPoint steer = sum - velocity;
            steer.limit(maxForce);
            
            applyForce(steer);
        }
}

void vehicle::update(){
    velocity += acceleration;
    location += velocity;
    velocity.limit(topSpeed);
    acceleration *= 0;
}

void vehicle::draw(){
    //float angle = ofRadToDeg(atan2(velocity.y,velocity.x)) + 90;
    
    ofPushMatrix();
  
    ofSetColor(175);
    ofTranslate(location.x, location.y);
    //ofRotate(angle);
    ofDrawCircle(0, 0, r);
   
    ofPopMatrix();
    
}