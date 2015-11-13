#version 120
#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect prevPosData;  // recive the previus position texture
uniform sampler2DRect velData;      // recive the velocity texture

void main(void){
    vec2 st = gl_TexCoord[0].st;    // gets the position of the pixel that it´s dealing with...
    
    vec2 pos = texture2DRect( prevPosData, st ).xy; // ... in order to look at a particulary place on it
    vec2 vel = texture2DRect( velData, st ).xy;     // Fetch both the pos and vel.
    
    pos += vel;
    
    // wrap
    if ( pos.x < 0.0)
        pos.x = 1.0;
    
    if ( pos.x > 1.0)
        pos.x = 0.0;
    
    if (pos.y < 0.0)
        pos.y = 1.0;
    
    if ( pos.y > 1.0)
        pos.y = 0.0;
    
    gl_FragColor.rgba = vec4(pos.x,pos.y,1.0,1.0);  // And finaly it store it on the position FBO
}