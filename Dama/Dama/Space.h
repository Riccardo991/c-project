#pragma once
#include "Piece.h"
#include <iostream>
#include <string>
using namespace std;

/*
 The object Space  reppresents the chessboard
- square is a   matrix of pieces
-  numWhite is the number of white pieces on chessboard
- numBlack is the number of black pieces on chessboard
*/

class Space :
	public Piece
{
private: 
	Piece** square;	
	int numWhite;
	int numBlack;

public:
	Space();
	Space(int n);
	
	void makeTeam();	 
	void printSpace();
	
	void goPiece(Piece p, int r, int c);
	void eatPiece(Piece eat, Piece died, int r, int c);
	void makeBigPiece( Piece p, int r, int c);
	void   goBigPiece(Piece p, int r, int c);
	void  eatBigPiece(Piece eat, Piece died,  int r, int c);

	bool continueGame();
	Piece getSquare(int r, int c);
	void setSquare(Piece p, int r, int c);
	int getNumWhite();
	int getNumBlack();
	
	~Space();

};  
 
