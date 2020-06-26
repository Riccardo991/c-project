#include "Space.h"
#include "Cell.h"
#include <iostream>
#include <string>
#include  <deque>
#include <cstdlib>
using namespace std;

Space::Space() {	 }

Space::Space(int r, int c) {
	dimRow = r;
	dimColon = c ;
	square = new Cell * [dimRow+1];
	for (int i = 0; i <= dimColon; i++) {
		square[i] = new Cell[dimColon+1];
	}
	square[0][0] = Cell("/");
	for (int i = 1; i <= r; i++) {
		if (i < 10) {
			char c = (char)(i + 48);
			string s = "";
			s = s + c;
			Cell e(s);
			square[i][0] = e;
		}
		else {
			int a = 48 + (i / 10);
			int b = 48 + (i % 10);
			char a1 = (char)a;
			char b1 = (char)b;
			string s = "";
			s = s + a1;
			s = s + b1;
			Cell e(s);
			square[i][0] = e;
		}
	}
	for (int i = 1; i <= c; i++) {
		if (i < 10) {
			char c = (char)(i + 48);
			string s = "";
			s = s + c;
			Cell e(s);
			square[0][i] = e;
		}
		else {
			int a = 48 + (i / 10);
			int b = 48 + (i % 10);
			char a1 = (char)a;
			char b1 = (char)b;
			string s = "";
			s = s + a1;
			s = s + b1;
			Cell e(s);
			square[0][i] = e;
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			Cell e("-", i, j);
			square[i][j] = e;
		}
	}
	numBomb = 0;
	numSeeCell = r * c;
}


//insert the bombs in the game-space
void Space::putBomb(int n) {
	numBomb = n;
	int j = 0;
	while (j < n) {
		int y = rand() % (dimRow - 1) + 1;
		int  x = rand() % (dimColon - 1) + 1;
		Cell e = square[y][x]; 
		if (e.getBomb() == false)  {
			e.setBomb(true);
			square[y][x] = e;
			j++;
		}
	}
}


// get a deque list with the neighbors cell of imput cell
deque<Cell> Space::getNeighbors(int r, int c) {
	deque<Cell> v;
	int y = r; int x = c;
	if (r > 1 && c > 1) {
		y = r - 1; x = c - 1;
		Cell e1 = square[y][x];
		v.push_back(e1);
	}
	if (r > 1) {
		y = r - 1; x = c;
		Cell e2 = square[y][x];
		v.push_back(e2);
	}
	if (r > 1 && c < dimColon) {
		y = r - 1; x = c + 1;
		Cell e3 = square[y][x];
		v.push_back(e3);
	}
	if (c < dimColon) {
		y = r; x = c + 1;
		Cell e4 = square[y][x];
		v.push_back(e4);
	}
	if (r < dimRow && c < dimColon) {
		y = r + 1; x = c + 1;
		Cell e5 = square[y][x];
		v.push_back(e5);
	}
	if (r < dimRow) {
		y = r + 1; x = c;
		Cell e6 = square[y][x];
		v.push_back(e6);
	}
	if (r < dimRow && c > 1) {
		y = r + 1; x = c - 1;
		Cell e7 = square[y][x];
		v.push_back(e7);
	}
	if (c > 1) {
		y = r; x = c - 1;
		Cell e8 = square[y][x];
		v.push_back(e8);
	}
	return v;
}


//get the danger (number of bombs) in the neighbors cell for each cell 
void Space::calcolateDanger() {
	for (int i = 1; i <= dimRow; i++) {
		for (int j = 1; j <= dimColon; j++) {
			Cell e = square[i][j];
			if (e.getBomb()) {
 				deque<Cell> v = getNeighbors(i, j);
				while (!v.empty()) {
					Cell e1 = v[0];
					if (!e1.getBomb()) {
						e1.addDanger(1);
						int r1 = e1.getRow();
						int c1 = e1.getColon();
						square[r1][c1] = e1;
					}
					v.pop_front();
				}
			}
		}
	}
}


//turn on  a set of neighbors  cells when the user select a good cell 
void Space::turnOnCell(int r, int c) {
	 deque<Cell> v = getNeighbors(r, c);
	 int k = dimRow / 3;
	while( ! v.empty()){ 
		Cell e = v[0];
		int z = e.getDanger();
		int re = e.getRow();
		int ce = e.getColon();
		string w = e.getSee();

		if (e.getBomb()== false && w == "-") {
			if (z >= 1) {
				char c = (char)(z + 48);
				string s = "";
				s = s + c;
				e.setSee(s);
				square[re][ce] = e;
				numSeeCell--;
			}

			if (z == 0 && k >= 0) {
				e.setSee("0");
				square[re][ce] = e;
				numSeeCell--;
				k++;
				deque<Cell> q = getNeighbors(re, ce);
				while(! q.empty()){
					Cell e1 = q[0];
					v.push_back(e1);
					q.pop_front();
				}
			}
		}
		v.pop_front();
	}
}

Cell Space::getElem(int r, int c) {
	Cell e = square[r][c];
	return e;
}

void Space::setElem(Cell e, int r, int c) {	 
	square[r][c] = e;
}

int Space::getDimRow() {
	return dimRow;
}

int Space::getDimColon() {
	return dimColon;
}

int Space::getNumBombs() {
	return numBomb;
}

int Space::getNumSeeCell() {
	return numSeeCell;
}

void Space::setNumSeeCell(int n) {
	numSeeCell = n;
}

void Space::printSpace() {
	cout << "minefield \n";
	for (int i = 0; i <= dimRow; i++) {
		for (int j = 0; j <= dimColon; j++) {
			Cell e = square[i][j];
			cout << e.getSee() << ", ";
		}
		cout << "\n";
	}
}
