#include "Cell.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Cell::Cell() {
	see = "";
	danger = 0;
	row = 0;
	colon = 0;
	bomb = false;
}

Cell::Cell(string s) {
	see = s;
	danger = 0;
	row = 0;
	colon = 0;
	bomb = false;
}

Cell::Cell(string s, int r, int c) {
	see = s;
	danger = 0;
	row = r;
	colon = c;
	bomb = false;
}

void Cell::addDanger(int n) {
	danger = danger + n;
}

string Cell::getSee() {
	return see;
}

bool Cell::getBomb() {
	return bomb;
}

int Cell::getDanger() {
	return danger;
}

int Cell::getRow() {
	return row;
}

int Cell::getColon() {
	return colon;
}

void Cell::setSee(string s) {
	see = s;
}

void Cell::setBomb(bool b) {
	bomb = b;
}

void Cell::setDanger(int n) {
	danger = n;
}

void Cell::setRow(int n) {
	row = n;
}

void Cell::setColon(int n) {
	colon = n;
}