#include "testApp.h"

int numParticles = 5000;
int textureRes = 0;
bool bTrails = true;

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    
    // set defaults
    
    maxVelocity = .1;
    maxForce = .1;
    particleSize = 1.0;
    desiredSeparation = 50.0 / ofGetWidth();
    neighborDistance = 10.0 / ofGetHeight();
    
    
    // load shaders
    // BASED ON THE EXCELLENT OF GPU PARTICLE EXAMPLE
    // shader for updating the texture that store the particles position on RG channels
    position.load("","shaders/posUpdate.frag");
    
    // shader for updating the texture that store the particles velocity on RG channels
    velocity.load("","shaders/velUpdate.frag");
    
    // takes input from ping pong buffers and outputs as adjustable circles
    render.setGeometryInputType(GL_POINTS);
    render.setGeometryOutputType(GL_TRIANGLES);
    render.setGeometryOutputCount(36);
    render.load("shaders/render.vert","","shaders/render.geom");
    
    // load ping-pong buffers
    // Seting the textures where the information ( position and velocity ) will be
    textureRes = (int)sqrt((float)numParticles);
    numParticles = textureRes * textureRes;
    
    // Make arrays of float pixels with position information
    
    float * pos = new float[numParticles*3];
    for (int x = 0; x < textureRes; x++){
        for (int y = 0; y < textureRes; y++){
            int i = textureRes * y + x;
            
            pos[i*3 + 0] = ofRandom(0.0, ofGetWidth())/ (float) ofGetWidth();
            pos[i*3 + 1] = ofRandom(0.0, ofGetHeight()) / (float) ofGetHeight();
            pos[i*3 + 2] = 0.0;
        }
    }
    
    posPingPong.allocate(textureRes, textureRes,GL_RGB32F);
    posPingPong.src->getTexture().loadData(pos, textureRes, textureRes, GL_RGB);
    posPingPong.dst->getTexture().loadData(pos, textureRes, textureRes, GL_RGB);
    
    delete [] pos;    // Delete the array
    
    
    // 2. Making arrays of float pixels with velocity information and the load it to a texture
    float * vel = new float[numParticles*3];
    for (int i = 0; i < numParticles; i++){
        vel[i*3 + 0] = ofRandom(-.01,.01);
        vel[i*3 + 1] = ofRandom(-.01,.01);
        vel[i*3 + 2] = 1.0;
    }
    // Load this information in to the FBO�s texture
    velPingPong.allocate(textureRes, textureRes,GL_RGB32F);
    velPingPong.src->getTexture().loadData(vel, textureRes, textureRes, GL_RGB);
    velPingPong.dst->getTexture().loadData(vel, textureRes, textureRes, GL_RGB);
    delete [] vel; // Delete the array
    
    // Allocate the final
    renderFBO.allocate(ofGetWidth(),ofGetHeight(), GL_RGBA);//32F);
    renderFBO.begin();
    ofClear(0, 0, 0, 0);
    renderFBO.end();
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    ofFloatColor color = ofColor();
    color.setSaturation(1.0);
    color.setBrightness(1.0);
    color.setHue(ofRandom(0.0, 1.0));
    
    for(int x = 0; x < textureRes; x++){
        for(int y = 0; y < textureRes; y++){
            mesh.addVertex(ofVec3f(x,y));
            mesh.addTexCoord(ofVec2f(x, y));
            
            mesh.addColor(color);
        }
    }
}

//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    velPingPong.dst->begin();
    ofClear(0);
    velocity.begin();
    velocity.setUniform1i("posWidth", velPingPong.src->getWidth());
    velocity.setUniform1i("posHeight", velPingPong.src->getWidth());
    velocity.setUniformTexture("backbuffer", velPingPong.src->getTexture(), 0);   // passing the previus velocity information
    velocity.setUniformTexture("posData", posPingPong.src->getTexture(), 1);      // passing the position information
    
    velocity.setUniform1f("maxspeed", maxVelocity / 100.0f);
    velocity.setUniform1f("maxforce", maxForce / 100.0f);
    
    // play with these to change your patterns
    velocity.setUniform1f("desiredSeparation", desiredSeparation);
    velocity.setUniform1f("neighborDistance", neighborDistance);
    
    // draw the source velocity texture to be updated
    velPingPong.src->draw(0, 0);
    
    velocity.end();
    velPingPong.dst->end();
    
    velPingPong.swap();
    
    
    // Position PingPong
    //
    // With the velocity calculated updates the position
    //
    posPingPong.dst->begin();
    ofClear(0);
    position.begin();
    position.setUniform1i("posWidth", velPingPong.src->getWidth());
    position.setUniform1i("posHeight", velPingPong.src->getWidth());
    position.setUniformTexture("prevPosData", posPingPong.src->getTexture(), 0); // Previus position
    position.setUniformTexture("velData", velPingPong.src->getTexture(), 1);  // Velocity
    
    // draw the source position texture to be updated
    posPingPong.src->draw(0, 0);
    
    position.end();
    posPingPong.dst->end();
    
    posPingPong.swap();
    
    // Rendering
    
    renderFBO.begin();
    
    ofPushMatrix();
    
    if ( !bTrails ){
        ofClear(0, 0, 0, 0);
    } else {
        ofSetColor(0,0,0,5);
        ofDrawRectangle(0,0,renderFBO.getWidth(), renderFBO.getHeight());
        ofSetColor(255);
    }
    render.begin();
    render.setUniformTexture("posTex", posPingPong.dst->getTexture(), 0);
    render.setUniform2f("screen", (float)2.0, (float)2.0);
    render.setUniform1f("pointSize", (float)particleSize);
    render.setUniform1f("screenSize", (float)ofGetWidth());
    
    ofPushStyle();
    ofSetColor(255);
    
    mesh.draw();
    
    ofPopStyle();
    
    render.end();
    ofPopMatrix();
    renderFBO.end();
}

//--------------------------------------------------------------
void testApp::draw(){
    renderFBO.draw(0,0);
    
    string toPrint = "Flockin' on the GPU\nMove mouse to set max force and velocity";
    toPrint += "\nMax Force = "+ofToString(maxForce);
    toPrint += "\nMax Velocity: "+ofToString(maxVelocity);
    toPrint += "\n\nPress +/- to change particle size";
    toPrint += "\nParticle Size: "+ofToString(particleSize);
    toPrint += "\nPress ' ' to draw trails: "+ofToString(bTrails);
    
    ofDrawBitmapString(toPrint, 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if ( key == '='){
        particleSize += .1;
    } else if ( key == '-'){
        particleSize -= .1;
        particleSize = fmax(0.0, particleSize);
    } else if ( key == ' '){
        bTrails = !bTrails;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    maxVelocity = (float) x/ofGetWidth();
    maxForce = (float) y / ofGetHeight();
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){}
