#pragma once
#include <iostream>
#include <string>
using namespace std;


/*
The Piece defines a cell on the  chessboard.
- If block  is true piece is a black cell else  is white cell.
- If live  is true main that there is a piece in the cell
- team defines if the piece is white, black or  is empty.
- type defines if the piece is normal or double
 - video  defines  what print in output
*/

class Piece
{
private:
	string team;
	string type;
	string video; 
	bool live;
	bool block; 
	int row;
	int colon;

public:
	Piece();
	Piece(string v, int r, int c, bool b);
	Piece(string s, string v,  int r, int c);
	
	void movePiece(int r, int c);

	// getter and setter methods 
	string getTeam();
	string getType();
	string getVideo();
	bool getLive();
	bool getBlock();
	int getRow();
	int getColon();
	void setType(string s);
	void setVideo(string v);
	void setLive(bool b);
	void setBlock(bool b);

	~Piece();

};

