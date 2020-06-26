#pragma once
#include "Space.h"
#include <iostream>
#include <string>
using namespace std;

/*
DamaRules is the controller  that verify if the players respect the    rules of game.
- player is the Piece of the   active player
- opponent is the piece of the waiting player
 */

class DamaRules :
	public Space
{
private:
	Space game;
	Piece player;
	Piece opponent;
	int jumpRow;
	int jumpColon;

public:
	DamaRules();
	DamaRules(Space z);

	bool selectWhitePiece( int r, int c);
	bool  selectBlackPiece( int r, int c);
	void updateGame(Space z);

	bool moveWhitePiece(  int r, int c);
	bool moveBlackPiece( int r, int c);
	 
	bool blackPieceEat(int r, int c);
	bool whitePieceEat(int r, int c);
	
	bool moveBigPiece( int r, int c);
	bool BigPieceEat( int r, int c);
	bool jumpBigPiece(int r, int c);
 
	Piece getPlayer();
	Piece getOpponent();
	void setPlayer(Piece p);
	int getJumpRow();
	int getJumpColon();

	~DamaRules();
};

