#version 120
#extension GL_ARB_texture_rectangle : enable
#define KERNEL_SIZE 9

uniform sampler2DRect backbuffer;   // recive the previus velocity texture
uniform sampler2DRect posData;      // recive the position texture

uniform int   posWidth;
uniform int   posHeight;

// flocking parameters
uniform float maxspeed;
uniform float maxforce;
uniform float desiredSeparation;
uniform float neighborDistance;

// vector utils
vec2 limit(vec2 v,float m){
    float lengthSquared = v.x*v.x + v.y*v.y;
    if( lengthSquared > m*m && lengthSquared > 0.0 ) {
        float ls = sqrt(lengthSquared);
        float ratio = m/ls;
        v *= ratio;
    }
    return v;
}

// Separation
// Method checks for nearby boids and steers away
vec2 separate(vec2 p,vec2 vel){
    vec2 steer = vec2(0.0,0.0);
    float count = 0.0;
    
    // For every boid in the system, check if it's too close
    
    for ( int x =0; x < posWidth; x ++){
        for (int y=0; y < posHeight; y++) {
            vec2 pos = texture2DRect( posData, vec2(x,y)).xy;
            
            float d = distance( p, pos );
            
            // If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
            if ((d > 0.0) && (d < desiredSeparation)) {
                // Calculate vector pointing away from neighbor
                vec2 diff = p;
                diff -= pos;
                diff = normalize(diff);
                diff /= d;          // Weight by distance
                steer += diff;
                count += 1.0;       // Keep track of how many
            }
        }
    }
    // Average -- divide by how many
    if (count > 0.0) {
        steer /= count;
    }
    
    // As long as the vector is greater than 0
    if (length(steer) > 0.0) {
        // Implement Reynolds: Steering = Desired - Velocity
        steer = normalize(steer);
        steer *= (maxspeed);
        steer /= vel;
        steer = limit(steer, maxforce);
    }
    return steer;
}

// Alignment
// For every nearby boid in the system, calculate the average velocity
vec2 align(vec2 p,vec2 vel){
    
    vec2 sum = vec2(0.0,0.0);
    float count = 0.0;
    for ( int x =0; x < posWidth; x ++){
        for (int y=0; y < posHeight; y++) {
            vec2 pos = texture2DRect( posData, vec2(x,y)).xy;
            vec2 otherVel = texture2DRect( backbuffer, vec2(x,y) ).xy;
            
            float d = distance( p, pos );
            
            if ((d > 0) && (d < neighborDistance)) {
                sum.x += otherVel.x;
                sum.y += otherVel.y;
                count = count + 1.0;
            }
        }
    }
    if (count > 0.0) {
        sum /= (count);
        sum = normalize(sum);
        sum *= (maxspeed);
        
        vec2 steer = sum - vel;
        steer = limit(steer, maxforce);
        return steer;
    } else {
        return vec2(0.0,0.0);
    }
}

vec2 seek(vec2 p,vec2 vel,vec2 target) {
    vec2 desired = target;  // A vector pointing from the location to the target
    desired -= p;
    
    // Normalize desired and scale to maximum speed
    desired = normalize(desired);
    desired *= (maxspeed);
    
    // Steering = Desired minus Velocity
    vec2 steer = desired;
    steer -= vel;
    steer = limit(steer, maxforce);  // Limit to maximum steering force
    return steer;
}

vec2 seekForce(vec2 p,vec2 vel,vec2 target) {
    vec2 desired = target;  // A vector pointing from the location to the target
    desired -= p;
    
    // Normalize desired and scale to maximum speed
    desired = normalize(desired);
    
    // Steering = Desired minus Velocity
    vec2 steer = desired;
    steer -= vel;
    return steer;
}

// Cohesion
// For the average location (i.e. center) of all nearby boids, calculate steering vector towards that location
vec2 cohesion(vec2 p,vec2 vel) {
    
    vec2 sum = vec2(0.0,0.0);
    float count = 0.0;
    for ( int x =0; x < posWidth; x ++){
        for (int y=0; y < posHeight; y++) {
            vec2 pos = texture2DRect( posData, vec2(x,y)).xy;
            vec2 otherVel = texture2DRect( backbuffer, vec2(x,y) ).xy;
            
            float d = distance( p, pos );
            
            if ((d > 0.0) && (d < neighborDistance)) {
                sum += pos;
                count = count + 1.0;
            }
        }
    }
    if (count > 0.0) {
        sum /= count;
        return seek(p, vel, sum);  // Steer towards the location
    } else {
        return vec2(0.0,0.0);
    }
}

vec2 applyForce(vec2 vel,vec2 force) {
    // We could add mass here if we want A = F / M
    return vel + force;
}


vec2 flock(vec2 p, vec2 v) {
    vec2 sep = separate(p,v);   // Separation
    vec2 ali = align(p,v);      // Alignment
    vec2 coh = cohesion(p,v);   // Cohesion
    // Arbitrarily weight these forces
    sep *= 1.5;
    ali *= 1.0;
    coh *= 1.0;
    
    // Add the force vectors to acceleration
    v = applyForce(v,sep);
    v = applyForce(v,ali);
    v = applyForce(v,coh);
    return v;
}

void main(void){
    vec2 st = gl_TexCoord[0].st;    // gets the position of the pixel that it´s dealing with...
    
    vec2 pos = texture2DRect( posData, st).xy;      // ... for gettinh the position data
    vec2 vel = texture2DRect( backbuffer, st ).xy;  // and the velocity
    
    // Calculates what´s going to be the next position without updating it.
    // Just to see if it collide with the borders of the FBO texture
    //
    vel = flock(pos, vel);
    
    gl_FragColor = vec4(vel.x,vel.y,0.0,1.0);   // Then save the vel data into the velocity FBO
}
