// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com


class mover {
public:
    
    ofPoint location, velocity, acceleration;
    float mass, g;
    
    mover() {

    }

    mover(float m, float x, float y, float g_) {
        mass = m;
        location.set(x,y);
        velocity.set(0,0);
        acceleration.set(0,0);
        g = g_;
    }
    
    void applyForce(ofPoint force) {
        force /= mass;
        acceleration += force;
    }
    
    void update() {
        velocity += acceleration;       // Velocity changes according to acceleration
        location += velocity;           // Location changes by velocity
        acceleration.set(0,0);          // We must clear acceleration each frame
    }
    
    void display() {
        ofSetLineWidth(2);
        ofSetColor(0,127);
        ofDrawCircle(location.x,location.y,mass*12);
    }
    
    ofPoint attract(mover m) {
        ofPoint force;
        force.set(location);
        force -= m.location;                        // Calculate direction of force
        float distance = force.length();            // Distance between objects
        distance = ofClamp(distance, 5.0, 25.0);    // Limiting the distance to eliminate "extreme" results for very close or very far
        force.normalize();                          // Normalize vector (distance doesn't matter here, we just want this vector for direction
        float strength = (g * mass * m.mass) / (distance * distance); // Calculate gravitional force magnitude
        force *= strength;                          // Get force vector --> magnitude * direction
        return force;
    }
};