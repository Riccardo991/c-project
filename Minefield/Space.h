#pragma once
#include "Cell.h"
#include <iostream>
#include <string>
#include   <deque>
using namespace std;

/*
The object  space represents the game-space of minefield.
The    matrix  square  is composed  by  objects elem and is the game-space.
The integer dimRow and dimColon is use to define the dimension of the matrix.
the integer numBombs is use to save the number of all bombs during a match.
The   integer  seeCell is use to save the number of cells that user turn on during the match.
*/

class Space :
	public Cell
{
private:
	Cell** square;
	int dimRow;
	int dimColon;
	int numBomb;
	int numSeeCell;

public:
	Space();
	Space(int r, int c);
	
	void putBomb(int n);
	void calcolateDanger();	
	void turnOnCell(int r, int c);
	deque<Cell> getNeighbors(int r, int c);
	void printSpace();

	// get methods 
	Cell getElem(int r, int c);
	int getDimRow();
	int getDimColon();
	int getNumBombs();
	int getNumSeeCell();

	// set methods 
	void setElem(Cell e , int r, int c); 
	void setNumSeeCell(int n);

};

