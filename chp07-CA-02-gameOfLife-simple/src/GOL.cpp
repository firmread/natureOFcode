//
//  GOL.cpp
//  NOC_7_02_GameOfLifeSimple
//
//  Created by Matthias Esterl on 7/5/13.
//
//

#include "GOL.h"

GOL::GOL(){
    w = 8;
    
    columns = ofGetWidth()/w;
    rows = ofGetHeight()/w;
    
    board.resize(columns, std::vector<int>(rows));
    init();
}

void GOL::init(){
    for (int i = 1; i < columns-1; i++) {
        for (int j = 1; j < rows-1; j++) {
            board[i][j] = int(ofRandom(2));
        }
    }
}

void GOL::generate(){
    vector< vector<int> > next(columns, vector<int>(rows));
    
    for ( int x = 1; x < columns-1; x++) {
        for ( int y = 1; y < rows-1; y++) {
            int neighbors = 0;
            
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    neighbors += board[x+i][y+j];
                }
            }
            
            neighbors -= board[x][y];

            if ((board[x][y] == 1) && (neighbors < 2)){
                next[x][y] = 0;           // Loneliness
            }
            else if ((board[x][y] == 1) && (neighbors > 3)){
                next[x][y] = 0;           // Overpopulation
            }
            else if ((board[x][y] == 0) && (neighbors == 3)){
                next[x][y] = 1;           // Reproduction
            }
            else{
                next[x][y] = board[x][y];  // Stasis
            }
        }
    }
    
    board = next;
}

void GOL::display(){
    for ( int i = 0; i < columns; i++) {
        for ( int j = 0; j < rows; j++) {
            
            ofFill();
            
            if (board[i][j] == 1){
                ofSetColor(0);   
            }
            else{
                ofSetColor(255);
            }
            ofDrawRectangle(i*w, j*w, w, w);
            
            ofNoFill();
            ofSetColor(0);
            ofDrawRectangle(i*w, j*w, w, w);
        }
    }
}