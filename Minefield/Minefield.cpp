// Minefield.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
 
#include "Cell.h"
#include "Space.h"
#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
using namespace std;

 
  //this project implements the Minefield game
 

// CooseSquare:  user select a cell in the game-space
void cooseSquare(Space z, int r, int c) {
    Cell e = z.getElem(r, c);
    int d = e.getDanger();
    char a = (char)(48 + d);
    string s = "";
    s = s + a;
    e.setSee(s);
    int nsc = z.getNumSeeCell();
    z.setNumSeeCell((nsc - 1));
    z.setElem(e, r, c);
    z.turnOnCell(r, c);
}

// live:  verify if user  select a good cell
bool live(Space z, int r, int c) {
    Cell e = z.getElem(r, c);
    return e.getBomb() == false;
}

// putFlag: user select a  flag in the game-space
void putFlag(Space z, int r, int c) {
    Cell e = z.getElem(r, c);
    if (e.getSee() == "-") {
        e.setSee("f");
    }
}

// removeFlag: user delete a flag in the game-space
void removeFlag(Space z, int r, int c) {
    Cell e = z.getElem(r, c);
    if (e.getSee() == "f") {
        e.setSee("-");
    }
}

// myContinue: a method that control   when the match  finish
bool myContinue(Space z) {
    int nb = z.getNumBombs();
    int nsc = z.getNumSeeCell();
    return nsc > nb;
}

int main()
{
    cout << " Welcom to minefield game\n" << "if you want play insert the dimensions of game space and the number of bombs  \n";
    int dr; int dc; int b; 
    cout << "digit  the number of rows";
    cin >> dr;
    cout << "\n digit the number of colons";
    cin >> dc;
    cout << "\n digit the number of bombs ";
    cin >> b;

    Space z(dr, dc);
    z.putBomb(b);
    z.calcolateDanger();

    cout << " Start game! \n";
    cout << "if you digit 1, you   play \n";
    cout << " if you digit 2 you  put a flag \n";
    cout << "if you digit 3 you remove a flag \n";
    cout<< "if you digit 4 you stop the game \n";
    
    int k = 0; int e = 0;  
    while(myContinue(z)) {
        z.printSpace();
        cout << "\n digit the comand number  ";
        cin >> k;
        switch (k) {
        case 1: 
            int r1; int c1; 
            cout << "digit the coordinate of the cell \n row:";
            cin >> r1;
            cout << "\n colon:";
            cin >> c1;
            if (live(z, r1, c1) ) {
                cooseSquare(z, r1, c1);
            }
            else {
                e = 1;
            }
            break;
        case 2:  
            int r2; int c2;
            cout << "digit the coordinate to put a flag. \n row:";
            cin >> r2;
            cout << "\n colon:";
            cin >> c2;
            putFlag(z, r2, c2); 
            break;
        case 3: 
            int r3; int c3;
            cout << "digit the coordinate to remove a flag. \n row:";
            cin >> r3;
            cout << "\n colon:";
            cin >> c3;
            removeFlag(z, r3, c3);
            break;
        }

        if (k == 4 || e == 1) {
            cout << "\n game over ";
            break;
        }
        }

    if (myContinue(z) == false) {
        cout << "\n win!! ";
    }
    }
