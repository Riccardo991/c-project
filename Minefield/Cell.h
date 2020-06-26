#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
The object elem is  the representation of    a cell of space game.
The String see is   use to  define what user can see during the game.
The integer row and colon  are use to define the position of the element in the space game.
The integer danger is use to indicate the number of bombs  that are in  the near cells.
*/

class Cell
{
private:
	string see;
	int danger;
	int row;
	int colon;
	bool bomb;

public:
	Cell();
	Cell(string s);
	Cell(string s, int r, int c);
	void addDanger(int n);

	// get methods 
	string getSee();
	bool getBomb();
	int getDanger();
	int getRow();
	int getColon();

	// set methods 
	void setSee(string s);
	void setBomb(bool b);
	void setDanger(int n);
	void setRow(int n);
	void setColon(int n);
};

