#include "DamaRules.h"
#include "Space.h"
#include "Piece.h"
#include <iostream>
#include <string>
using namespace std;

DamaRules::DamaRules() {}

DamaRules::DamaRules(Space z) {
	game = z;
	 
	jumpRow = 0;
	jumpColon = 0;
}


// selectBlackPiece verify if the black player  takes a  black piece 
bool  DamaRules::selectBlackPiece( int r, int c) {		 
	if ((1 <=r <= 8) && (1 <=c <= 8)) {
		Piece p = game.getSquare(r, c);
		string s = p.getTeam();
		if (p.getLive() && s == "black" && p.getBlock() == false ) {
			player = p;			
			return true; 
		}
	}
	return false;
}


// selectWhitePiece verify if the white player  takes a  white piece 
bool  DamaRules::selectWhitePiece(int r, int c) {	
	if ((1 <= r <= 8) && (1 <= c <= 8)) {
		Piece p = game.getSquare(r, c);
		string s = p.getTeam();
		if (p.getLive() && s == "white" && p.getBlock() == false) {
			player = p;			
			return true;
		}
	}
	return false;
}


void DamaRules::updateGame(Space z) {
	game = z;
	player = Piece();
	opponent = Piece();
	jumpRow = 0;
	jumpColon = 0;
}


//  moveWhitePiece verify if  the white piece can move in the input coordinates
bool DamaRules::moveWhitePiece(int r, int c) {
	if ((1 <= r <= 8) && (1 <= c <= 8)) {
		int rt = r ; int cl = c; int cr = c;
		rt--; cl--; cr++;
		int rp = player.getRow();
		int cp = player.getColon();
		if (rp  == rt) {
			if((cp == cl) || (cp == cr)){
				jumpRow = r;
					jumpColon = c;
			return true;
			}
		}
	}
	return false;
}


//  moveBlackPiece verify if  the black piece can move in the input coordinates
bool DamaRules::moveBlackPiece(int r, int c) {
	if ((1 <= r <= 8) && (1 <= c <= 8)) {
		int rd = r; int cl = c; int cr = c;
		rd++; cl--; cr++;
		int rp = player.getRow();
		int cp = player.getColon();
			if (rp  == rd) {
				if ((cp == cl) || (cp == cr)) {
					jumpRow = r;
					jumpColon = c;
					return true;
				}
			}
		}
	return false;
}


//  eatBlackPiece verify if the black player can eat the white piece and return the   destination coordinates after jump   
bool DamaRules::blackPieceEat(int r, int c) {
	Piece eat = player;
	if ( moveBlackPiece(r, c) && selectWhitePiece(r, c)) {
		opponent = game.getSquare(r, c);
		player = eat;		
			int cp1 = player.getColon()+1;
			int cp2 = player.getColon()-1;
			if (cp1  == c && opponent.getType() == "normal") {
				int sr = r-1; int sc = c + 1;
				if (sr >= 1 && sc <= 8) {
					Piece spot = game.getSquare(sr, sc);
					if (spot.getLive() == false && spot.getBlock() == false) {
						jumpRow = sr;
						jumpColon = sc;
						return true;
					}
				}
			}
			  if (cp2  == c && opponent.getType() == "normal") {
				int rs = r- 1; int cs = c - 1;
				if (rs >= 1 && cs >= 1) {
					Piece spot = game.getSquare(rs, cs);
					if (spot.getLive() == false && spot.getBlock() == false) {
						jumpRow = rs;
						jumpColon = cs;
						return true;
					}
				}
			} else { 
				  return false;
		}
	}	 
	return false;
}


//  eatWhitePiece verify if the white player can eat the black piece and return the   destination coordinates after jump   
bool  DamaRules::whitePieceEat(int r, int c) {
	Piece eat = player;
	if ( moveWhitePiece(r, c) && selectBlackPiece(r, c)) {
		opponent = game.getSquare(r, c);
		player = eat;		
		int pc1 = player.getColon() + 1;
		int pc2 = player.getColon() - 1;;
		if (pc1 == c && opponent.getType() == "normal") {
			int sr = r + 1; int sc = c+ 1;
			if (sr <=8 &&  sc <= 8) {
				Piece spot = game.getSquare(sr, sc);
				if (spot.getLive() == false && spot.getBlock() == false ) {
					jumpRow = sr;
					jumpColon = sc;
					return true;
				}
			}
		}
		 if (pc2  == c && opponent.getType() == "normal") {
			int sr = r + 1; int sc = c - 1;
			if (sr <= 8 && sc >= 1) {
				Piece spot = game.getSquare(sr, sc);
				if (spot.getLive() == false && spot.getBlock() == false) {
					jumpRow = sr;
					jumpColon = sc;
					return true;
				}
			}
		}
		else { 
			 return false;
		}
	}	 
	return false;
}


// moveBigPiece verify if  the input big piece can move 
bool DamaRules::moveBigPiece( int r, int c) {
	if ((1 <= r <= 8) && (1 <= c <= 8)) {
		int rd = r; int cl = c; int cr = c;
		rd--; cl--; cr++;
		int rp = player.getRow();
		int cp = player.getColon();
		if (rp == rd) {
			if (cp == cl || cp == cr) {
				Piece s = game.getSquare(r, c);
				if (s.getLive() == false && s.getBlock() == false ) {					
					jumpRow = r;
					jumpColon = c;
					return true;
				}
			}
		}
		int rt = r; rt++;
		if (rp == rt) {
			if (cp == cl || cp == cr) {
				Piece s = game.getSquare(r, c);
				if (s.getLive() == false) {					
					jumpRow = r;
					jumpColon = c;
					return true;
				}
			}
		}
	}
	return false;
}
 

//  eatBigPiece verify if the  big piece can eat the opponent and return the   destination coordinates after jump   
bool DamaRules::BigPieceEat(int r, int c) {
	string s = player.getTeam();
	Piece eat = player;
	if (s == "white") {
		if ( moveBigPiece(r, c) && selectBlackPiece(r, c)) {
			player = eat;
			opponent = game.getSquare(r, c);
			if (jumpBigPiece(r, c)) {
				return true;
			}
		}
		return false;
	}
	else {
		if ( moveBigPiece(r, c) && selectWhitePiece(r, c)) {
			player = eat;
			opponent = game.getSquare(r, c);
			if (jumpBigPiece(r, c)) { return true; }
		} return false;
	}
 }
				

// jumpBigpiece a submethod  that calcolate the destination coordinates     after  big piece jump  
		bool DamaRules::jumpBigPiece(int r, int c){
		int rp = player.getRow();
		int cp = player.getColon();
		int re1 = r; int ce1 = c;
		if (rp ==( re1 - 1) && cp == (ce1 - 1)) {
			int rs = r + 1; int cs = c + 1;
			if (rs <= 8 && cs <= 8) {
				Piece spot = game.getSquare(rs, cs);
				if (spot.getLive() == false) {
					jumpRow = rs;
					jumpColon = cs;
					return true;
				}
			}
		}
		int re2 = r; int ce2 = c;
		if (rp ==( re2 - 1) && cp == (ce2 + 1)) {
			int rs = r + 1; int cs = c - 1;
			if (rs <= 8 && cs >= 1) {
				Piece spot = game.getSquare(rs, cs);
				if (spot.getLive() == false) {
					jumpRow = rs;
					jumpColon = cs;
					return true;
				}
			}
		}
		int re3 = r; int ce3 = c;
		if (rp ==( re3 + 1) && cp ==( ce3 + 1)) {
			int rs = r - 1; int cs = c - 1;
			if (rs >= 1 && cs >= 1) {
				Piece spot = game.getSquare(rs, cs);
				if (spot.getLive() == false) {
					jumpRow = rs;
					jumpColon = cs;
					return true;
				}
			}
		}
		int re4 = r; int ce4 = c;
		if ((re4 + 1) == rp &&( ce4 - 1) == cp) {
			int rs = r - 1; int cs = c + 1;
			if (rs >= 1 && cs <= 8) {
				Piece spot = game.getSquare(rs, cs);
				if (spot.getLive() == false) {
					jumpRow = rs;
					jumpColon = cs;
					return true;
				}
			}
		}
	return false;
}

		Piece DamaRules::getPlayer() {
			return player;
		}

		Piece DamaRules::getOpponent() {
			return opponent;
		}

		void DamaRules::setPlayer(Piece p) {
			player = p;
		}

		int DamaRules::getJumpColon() {
			return jumpColon;
		}

		int DamaRules::getJumpRow() {
			return jumpRow;
		}

		DamaRules::~DamaRules() {}
