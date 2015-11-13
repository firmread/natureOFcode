#include "FlowField.h"
#include "ofApp.h"

FlowField::FlowField(int initResolution)
{
    resolution = initResolution;
    std::cout<< resolution <<std::endl;
    cols = ofGetWidth() / resolution;
    std::cout<< "Width: " << ofGetWidth() << " Cols: " << cols <<std::endl;
    rows = ofGetHeight() / resolution;
    std::cout<< "Height: " << ofGetHeight() << " Rows: " << rows <<std::endl;

    // Using a one dimensional vector instead of 2 dimensional array as in NOC
    field = vector<float> (cols * rows);
    ofVec2f screenCenter = ofVec2f(ofGetWidth() / 2,ofGetHeight() / 2);

     for(int rowPos=0; rowPos< rows ; rowPos++)
    {
        for(int colPos=0; colPos< cols ; colPos++)
        {
            // Not sure that this is the best way to do this, seems that we shouldn't need to make the adjustment to subtract 180 degree when x is greater than 0...
            // Note that I also stored the angles in the vector instead of ofVec2fs - mainly because I didn't read the exercise instructions properly!
            ofVec2f screenPosition = ofVec2f(colPos*resolution - screenCenter.x,rowPos*resolution - screenCenter.y);
            float angle = ofRadToDeg(atan(screenPosition.y / screenPosition.x ));
            if(screenPosition.x > 0) angle -= 180 ;
            field[colPos + (rowPos * cols)] = angle;
        }
    }
}

void FlowField::displayFlowField()
{

    /*
    Uncomment to draw an x at the centre of the screen
    ofVec2f screenCenter = ofVec2f(ofGetWidth() / 2,ofGetHeight() / 2);
    ofSetColor(255,0,0,255);
    ofLine(screenCenter.x - 50,screenCenter.y-50,screenCenter.x+50,screenCenter.y+50);
    ofLine(screenCenter.x + 50,screenCenter.y-50,screenCenter.x-50,screenCenter.y+50);
    */

    for(int rowPos=0; rowPos< rows ; rowPos++)
    {
        for(int colPos=0; colPos< cols ; colPos++)
        {
            ofFill();
            ofPushMatrix();
            // add half resolution to each dimension to put us in center of each 'cell'
            ofTranslate((colPos*resolution) + resolution/2,rowPos*resolution  + resolution/2);
            float angleToRotate = field[colPos + (rowPos * cols)];
            ofRotate(angleToRotate);
            drawArrow(resolution);
            ofSetColor(0,0,255,255);
            int angFloored = angleToRotate;
            // ofDrawBitmapString(ofToString(angFloored), 0,0); // uncomment to output angle at position for debugging
            ofPopMatrix();
        }
    }
}

void FlowField::drawArrow(float length)
{
    // half the length is subtracted from the x point positions to move the rotation axis to the center
    ofSetColor(0,0,0,255);
    ofLine(-length/2, 0, length/2, 0);
    ofLine(-length/2 + length*0.8, length*0.1, length/2, 0);
    ofLine(-length/2 + length*0.8, length*-0.1, length/2, 0);
}
