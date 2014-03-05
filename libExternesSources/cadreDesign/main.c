//Fichiers includes.
//******************
#include <stdio.h>
#include <windows.h>


//Variables constantes.
//*********************
#define HG 201
#define HD 187
#define BD 188
#define BG 200
#define VERT 186
#define HORI 205

#define COL_LEFT 5
#define LIN_TOP 2

void afficherCadre(int couleurCadre, int coinPos[4])
{
    //Variables.
    //**********
    int colCrt, linCrt;

    textcolor(couleurCadre);

    //Coin supérieur gauche & coin inférieut gauche.
    //**********************************************
    gotoxy(COL_LEFT, LIN_TOP); printf("%c", HG);
    gotoxy(coinPos[1], LIN_TOP); printf("%c", HD);
    gotoxy(COL_LEFT, coinPos[3]); printf("%c", BG);
    gotoxy(coinPos[1], coinPos[3]); printf("%c", BD);
    Sleep(5);

    //Ligne horizontale.
    //******************
    for(colCrt=COL_LEFT+1; colCrt<coinPos[1]; colCrt++)
    {
        gotoxy(colCrt, coinPos[2]); printf("%c", HORI);
        gotoxy(colCrt, coinPos[3]); printf("%c", HORI);
        Sleep(5);
    }

    //Ligne verticale.
    //****************
    for(linCrt=LIN_TOP+1; linCrt<coinPos[3]; linCrt++)
    {
        gotoxy(coinPos[1], linCrt); printf("%c",VERT);
        gotoxy(coinPos[0], linCrt); printf("%c",VERT);
        Sleep(10);
    }
}
