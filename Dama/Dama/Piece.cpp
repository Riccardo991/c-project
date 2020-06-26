#include "Piece.h"
#include <iostream>
#include <string>
using namespace std;

Piece::Piece(){}

Piece::Piece(string v, int r, int c, bool b) {
	team = "";
	type = "";
	video = v;
	live = false;
	block = b;
	row = r;
	colon = c;
}

Piece::Piece(string s, string v,  int r, int c) {
	team = s;
	type = "normal";
	video = v;
	live = true;
	block = false;
	row = r;
	colon = c;
}
 
void Piece::movePiece(int r, int c) {
	row = r;
	colon = c;
}

string Piece::getTeam() {
	return team;
}

string Piece::getType() {
	return type;
}

string Piece::getVideo() {
	return video;
}

bool Piece::getLive() {
	return live;
}

bool Piece::getBlock() {
	return block;
}

int Piece::getRow() {
	return row;
}

int Piece::getColon() {
	return colon;
}

void Piece::setType(string s) {
	type = s;
}

void Piece::setVideo(string v) {
	video = v;
}

void Piece::setLive(bool b) {
	live = b;
}

void Piece::setBlock(bool b) {
	block = b;
}

Piece::~Piece() {}
