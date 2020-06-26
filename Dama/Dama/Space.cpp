#include "Space.h"
#include "Piece.h"
#include <iostream>
#include <string>
using namespace std;

Space::Space(){}

// create the  chessboard
Space::Space(int n) {
	
	square = new Piece* [9];
	for (int i = 0; i < 9; i++) {
		square[i] = new Piece[9];
	}
	Piece z("/", 0, 0, true);
	square[0][0] = z;
	for (int i = 1; i < 9; i++) {
		char  a = (char)(48 + i);
		string s = "";
		s = s + a;
		Piece x(s, 0, i, true);
		square[0][i] = x;
		Piece y(s, i, 0, true);
		square[i][0] = y;
	}
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 1) {
					Piece p("-", i, j, true);
					square[i][j] = p;
				}
				else {
					Piece p(".", i, j, false);
					square[i][j] = p;
				}
			}
			else {
				if (j % 2 == 0) {
					Piece p("-", i, j, true);
					square[i][j] = p;
				}
				else {
					Piece p(".", i, j, false);
					square[i][j] = p;
				}
			}
		}
	}
	numWhite  = 0;
	  numBlack= 0;
}

// makeTeam  puts the pieces  on chessboard in the initial order. 
void Space::makeTeam() {
	numWhite = 12;
	numBlack = 12;
	for (int i = 1; i < 9; i++) {
		if (i % 2 == 1) {
			Piece p1("white", "W", 1, i);
			square[1][i] = p1;
			Piece p3("white", "W", 3, i);
			square[3][i] = p3;
			Piece p7("black", "B", 7, i);
			square[7][i] = p7;
		}
		else {
			Piece p2("white", "W", 2, i);
			square[2][i] = p2;
			Piece p6("black", "b", 6, i);
			square[6][i] = p6;
			Piece p8("black", "B", 8, i);
			square[8][i] = p8;
		}
	}
}
 
void Space::printSpace() {	 
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {			
			Piece p = square[i][j];
			string s = p.getVideo();
			cout << s << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

// goPiece moves the  input piece  on the chessboard 
void Space::goPiece(Piece p, int r, int c) {
	int pr = p.getRow();
	int pc = p.getColon();	
	 Piece t(".", pr, pc, false);
	 square[pr][pc] = t;
	 p.movePiece(r, c);
	 square[r][c] = p;	  
	if (r == 1 || r == 8) { makeBigPiece(p, r, c);  }
 }

// eatPiece  moves the eater piece and remove the opponent  
void Space::eatPiece(Piece eat, Piece died, int r, int c) {
	int er = eat.getRow();
	int ec = eat.getColon();
	string s = died.getTeam();
	int dr = died.getRow();
	int dc = died.getColon();	
	Piece p1(".", er, ec, false);
	square[er][ec] = p1;
	Piece p2(".", dr, dc, false);
	square[dr][dc] = p2;
	eat.movePiece(r, c);
	square[r][c] = eat;	
	if (s == "white") {
		numWhite--;
	}
	else {
		numBlack--;
	}	
	if (r == 1 || r == 8) { makeBigPiece(eat, r, c); }
}

// makeBigPiece   trasforms the input piece in the double piece 
void Space::makeBigPiece(Piece p, int r, int c) {	
	string s = p.getTeam();		
	if ( r == 8 && s == "white") {
		p.setVideo("WW");
		p.setType("double");
		square[r][c] = p;
	}
	if (r == 1 && s == "black"){
		p.setVideo("BB");
		p.setType("double");
		square[r][c] = p;
	}	
}

//  goBigPiece moves the input double piece on  chessboard
void Space::goBigPiece(Piece p, int r, int c) {
	int pr = p.getRow();
	int pc = p.getColon();	 
	Piece t(".", pr, pc, false);
	square[pr][pc] = t;
	p.movePiece(r, c);
	square[r][c] = p;	 
}

// eatBigPiece moves the eater big piece and remove the opponent 
void Space::eatBigPiece(Piece eat, Piece died, int r, int c) {
	int er = eat.getRow();
	int ec = eat.getColon();
	string s = died.getTeam();
	int dr = died.getRow();
	int dc = died.getColon();	
	Piece p1(".", er, ec, false);
	square[er][ec] = p1;
	Piece p2(".", dr, dc, false);
	square[dr][dc] = p2;
	eat.movePiece(r, c);
	square[r][c] = eat;	 
	if (s == "white") {
		numWhite--;
	}
	else {
		numBlack--;
	}
}

// continueGame  verify  if the match can continue 
bool Space::continueGame() {
	return (numWhite > 0 && numBlack > 0);
}

Piece Space::getSquare(int r, int c) {
	Piece p;
	p = square[r][c]; 
	return p;
}

void Space::setSquare(Piece p, int r, int c) {
	square[r][c] = p;
}

int Space::getNumBlack() {
	return numBlack;
}

int Space::getNumWhite() {
	return numWhite;
}

Space::~Space() {}
 
