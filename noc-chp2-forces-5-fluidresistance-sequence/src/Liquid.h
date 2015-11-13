// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com


class Liquid {
public:
    
    // Liquid is a rectangle
    float x,y,w,h;
    // Coefficient of drag
    float c;
    
    Liquid() {
        
    }
    
    Liquid(float x_, float y_, float w_, float h_, float c_) {
        x = x_;
        y = y_;
        w = w_;
        h = h_;
        c = c_;
    }
    
    // Is the Mover in the Liquid?
    bool contains(Mover m) {
        ofVec2f l = m.location;
        if (l.x > x && l.x < x + w && l.y > y && l.y < y + h) {
            return true;
        }
        else {
            return false;
        }
    }
    
    // Calculate drag force
    ofVec2f drag(Mover m) {
        // Magnitude is coefficient * speed squared
        float speed = m.velocity.length();
        float dragMagnitude = c * speed * speed;
        
        // Direction is inverse of velocity
        ofVec2f dragForce = m.velocity;
        dragForce *= -1;
        
        // Scale according to magnitude
        // dragForce.setMag(dragMagnitude);
        dragForce.normalize();
        dragForce *= dragMagnitude;
        return dragForce;
    }
    
    void display() {
        ofSetColor(50);
        ofRect(x,y,w,h);
    }
    
};