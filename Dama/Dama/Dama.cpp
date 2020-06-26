// Dama.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
 
#include "Piece.h"
#include "Space.h"
#include "DamaRules.h"
#include <iostream>
#include <string>
using namespace std;

// this project implements the Dama game 

int main()
{
    cout << "Welcon on Dama game! \n";
    Space z(8);
    z.makeTeam();
    DamaRules dr(z);
    int turn = 1;
    int r = 0; int c = 0; int k = 0; int e = 0;
     
    z.printSpace();
    cout << " start play! \n";
 
        while (z.continueGame()) {
            if (turn % 2 == 1) {
                cout << " Dama   (turn " << turn << " ) \n";
                z.printSpace();
                cout << " white player is your turn, select  a piece. \n digit row:";
                cin >> r;
                cout << "\n digit colon:";
                cin >> c;

                if (dr.selectWhitePiece(r, c) ) {                
                    cout << " digit 1 to move or digit 2 to eat, or  digit 3 to finish match";
                    cin >> k;
                    Piece p = dr.getPlayer();
                    
                    switch (k) {
                    case 1:
                    {   int r1 = 0; int c1 = 0;
                    cout << "\n to move digit  coordinate of next cell. \n digit row:";
                    cin >> r1;
                    cout << "\n digit colon:";
                    cin >> c1;
                    if (p.getType() == "normal" && dr.moveWhitePiece(r1, c1)) {
                        z.goPiece(p, r1, c1);
                        dr.updateGame(z);
                        turn++;
                        e++;
                    }
                    if (p.getType() == "double" && dr.moveBigPiece(r1, c1)) {
                        z.goBigPiece(p, r1, c1);
                        dr.updateGame(z);
                        turn++;
                        e++;
                    }
                    }
                        break;
                    case 2:
                    { int r2 = 0; int c2 = 0;
                    cout << "digit coordinate of the piece that you want eat. \n digit row:";
                    cin >> r2;
                    cout << "\n digit colon:";
                    cin >> c2;

                    if (p.getType() == "normal" && dr.whitePieceEat(r2, c2)) {
                        Piece o = dr.getOpponent();
                        int jr = dr.getJumpRow();
                        int jc = dr.getJumpColon();
                        z.eatPiece(p, o, jr, jc);
                        dr.updateGame(z);
                        turn++;
                        e++;
                    }
                    if (p.getType() == "double" && dr.BigPieceEat(r2, c2)) {
                        Piece o = dr.getOpponent();
                        int jr = dr.getJumpRow();
                        int jc = dr.getJumpColon();
                        z.eatBigPiece(p, o, jr, jc);
                        dr.updateGame(z);
                        turn++;
                        e++;
                    }
                    }
                        break;  
                     
                  } 
                }
                    else {
                        cout << "error, try again \n";
                    }
                }
                else {
                cout << " Dama   (turn " << turn << " ) \n";
                z.printSpace();
                cout << " black  player is your turn, select  a piece. \n digit row:";
                cin >> r;
                cout << "\n digit colon:";
                cin >> c;

                if (dr.selectBlackPiece(r, c)) {
                    cout << " digit 1 to move or digit 2 to eat, or  digit 3 to finish match";
                    cin >> k;
                    Piece p = dr.getPlayer();

                    switch (k) {
                    case 1:
                    {  int r1 = 0; int c1 = 0;
                    cout << "\n digit  coordinate of next cell  to move piece.   \n digit row:";
                    cin >> r1;
                    cout << "\n digit colon:";
                    cin >> c1;
                    if (p.getType() == "normal" && dr.moveBlackPiece(r1, c1)) {
                        z.goPiece(p, r1, c1);
                        dr.updateGame(z);
                        turn++;
                        e++;
                    }
                    if (p.getType() == "double" && dr.moveBigPiece(r1, c1)) {
                        z.goBigPiece(p, r1, c1);
                        dr.updateGame(z);
                        turn++;
                        e++;
                    }
                    }
                        break;
                    case 2:
                        int r2 = 0; int c2 = 0;
                        cout << "digit coordinate of the piece that you want eat. \n digit row:";
                        cin >> r2;
                        cout << "\n digit colon:";
                        cin >> c2;

                        if (p.getType() == "normal" && dr.blackPieceEat( r2, c2)) {
                            Piece o = dr.getOpponent();
                            int jr = dr.getJumpRow();
                            int jc = dr.getJumpColon();
                            z.eatPiece(p, o, jr, jc);
                            dr.updateGame(z);
                            turn++;
                            e++;
                        }
                        if (p.getType() == "double"&&dr.BigPieceEat(r2, c2)) {                            
                            Piece o = dr.getOpponent();
                            int jr = dr.getJumpRow();
                            int jc = dr.getJumpColon();
                            z.eatBigPiece(p, o, jr, jc);
                            dr.updateGame(z);
                            turn++;
                            e++;
                        }
                        break;
                    }
                }
                else {
                    cout << "error, try again \n";
                }
            }

            if (e == 0) {
                cout << "error, try again \n";                 
            }            
            if (k == 3) { break; }
        }

        int wp = z.getNumWhite();
        int bp = z.getNumBlack();
        if (wp > bp) {
            cout << "\n the whinner is white player!! ";
        }
        else {
            cout << "\n the winner is black player!!";
        }
 
        cout << "\n end game";
}
