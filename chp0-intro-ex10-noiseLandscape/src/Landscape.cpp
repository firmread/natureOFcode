//
//  Landscape.cpp
//  introduction_ex10_NoiseLandscape
//
//  Created by Gorka Cortazar on 12/11/12.
//
//

#include "Landscape.h"

Landscape::Landscape() {
    
}

Landscape::Landscape(int scl_, int w_, int h_) {
    scl = scl_;
    w = w_;
    h = h_;
    cols = w/scl;
    rows = h/scl;
    zoff = 0.0;
    //ofLogVerbose()<< " cols " << cols <<
    //equivalento to allocation of arrays in Java, fil the array with zeros at initial value
    //C++ returns we try to access a non defined value (CHECK)
    for(int i = 0; i < cols; i++) {
        vector<float> v;
        for(int j = 0; j < rows; j++) {
            v.push_back(0.0f);
        }
        z.push_back(v);
    }
}

// Calculate height values (based off a neural netork) //REVIEW
void Landscape::calculate() {
    float xoff = 0;
    for(int i = 0; i < cols; i++) {
        float yoff = 0;
        for(int j = 0; j < rows; j++) {
            z[i][j] = ofMap(ofNoise(xoff,yoff,zoff),0,1,-120,120);
            yoff += 0.1;
        }
        xoff += 0.1;
    }
    zoff += 0.1;
}

void Landscape::render() {
    // Every cell is an individual quad
    // (could use quad_strip here, but produces funny results, investigate this)
    // TECNECOLLECTIVE: Bug to fix, investigate how to change default renderer to QUADS
    for (int x = 0; x < z.size()-1; x++)
    {
        for (int y = 0; y < z[x].size()-1; y++)
        {
            // one quad at a time
            // each quad's color is determined by the height value at each vertex
            // (clean this part up)
            ofSetColor(100,100);
            ofFill();
            ofPushMatrix();
                ofBeginShape();
                   ofTranslate(x*scl-w/2, y*scl-h/2, 0);
                    ofVertex(0, 0, z[x][y]);
                    ofVertex(scl, 0, z[x+1][y]);
                    ofVertex(scl, scl, z[x+1][y+1]);
                    ofVertex(0, scl, z[x][y+1]);
                ofEndShape(true);
            ofPopMatrix();
            
            //repeat to draw the lines, ofx implemets this differently than Processing
            ofNoFill();
            ofSetColor(0,0,0);
            ofBeginShape();
            ofPushMatrix();
                ofBeginShape();
                    ofTranslate(x*scl-w/2, y*scl-h/2, 0);
                    ofVertex(0, 0, z[x][y]);
                    ofVertex(scl, 0, z[x+1][y]);
                    ofVertex(scl, scl, z[x+1][y+1]);
                    ofVertex(0, scl, z[x][y+1]);
                    ofEndShape(true);
            ofPopMatrix();
        }
    }
}
