
#include "GOL.h"

GOL::GOL(){
    w = 8;
    
    columns = ofGetWidth()/w;
    rows = ofGetHeight()/w;
    
    board.resize(columns, std::vector<GOLCell*>(rows));
    init();
}

void GOL::init(){
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            board[i][j] = new GOLCell(i*w, j*w, w);
        }
    }
}

void GOL::generate(){
    for ( int i = 0; i < columns; i++) {
        for ( int j = 0; j < rows; j++) {
            board[i][j]->savePrevious();
        }
    }
    
    for (int x = 0; x < columns; x++){
        for (int y = 0; y < rows; y++){
            int neighbors = 0;
            
            for (int i = -1; i <= 1; i++){
                for (int j = -1; j <= 1; j++){
                    neighbors += board[(x+i+columns)%columns][(y+j+rows)%rows]->previous;
                }
            }
            
            neighbors -= board[x][y]->previous;
            
            if ((board[x][y]->state == 1) && (neighbors <  2)){
                board[x][y]->newState(0);            // Loneliness
            }
            else if ((board[x][y]->state == 1) && (neighbors >  3)){
                board[x][y]->newState(0);            // Overpopulation
            }
            else if ((board[x][y]->state == 0) && (neighbors == 3)){
                 board[x][y]->newState(1);           // Reproduction
            }
        }
    }
}

void GOL::display(){
    for ( int i = 0; i < columns; i++) {
        for ( int j = 0; j < rows; j++) {
            board[i][j]->display();
        }
    }
}