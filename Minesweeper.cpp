#include "Minesweeper.h"
#include <cstdlib>
#include <iostream>

Minesweeper::Minesweeper(int width, int height, int mines) {
    this->width = width;
    this-> height = height;
    this->mines = mines;
    this->totalNumTiles = width*height;
    this->numOpenTiles = 0;
    this->gameIsOver = false;

    gameBoard = new Tile* [height];
    for (int i = 0; i < width; i++) {
        gameBoard[i] = new Tile [width];
    }

    for (int c = 0; c < mines; c++) {
        int a = (rand()%height);
        int b = (rand() % width);
        if (gameBoard[a][b].mine) {
            c--;
        }
        gameBoard[a][b].mine = true;
    }
}

Minesweeper::~Minesweeper() {
    for (int i = 0; i < height; i++){
        delete [] gameBoard[i];
    }
    delete[] gameBoard;
    gameBoard = nullptr;
}

bool Minesweeper::isGameOver() const {
    return gameIsOver;

}

bool Minesweeper::isTileOpen(int row, int col) const {
    return gameBoard[row][col].open;
}

bool Minesweeper::isTileMine(int row, int col) const {
    return gameBoard[row][col].mine;
}

void Minesweeper::openTile(int row, int col) {
    gameBoard[row][col].open = true;
    numOpenTiles++;
    if (gameBoard[row][col].mine)
        gameIsOver = true;
    if (numAdjacentMines(row, col)==0){
        for (int i = (row-1); i <= (row+1); i++) {
            for (int j = (col-1); j <=(col+1) ; j++) {
                if ((i<height && i>=0) && (j<width && j>=0))
                    if (!isTileOpen(i,j))
                        openTile(i,j);
            }
        }
    }
    if((totalNumTiles-numOpenTiles)==mines){
        gameIsOver = true;
        std::cout << "Gratulerer, du vant!\n";
    }
}

int Minesweeper::numAdjacentMines(int row, int col) const {
    int counter = 0;
    for (int i = (row-1); i <= (row+1); i++) {
        for (int j = (col-1); j <=(col+1) ; j++) {
            if ((i<height && i>=0) && (j<width && j>=0))
                counter += isTileMine(i,j);
        }
    }
    return counter;
}
