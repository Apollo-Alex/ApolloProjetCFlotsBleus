/*******************************
    *   @autheur:   GILLES A.
    *   @projet:    Projet C - Les Flots Bleus
    *   @date:      2014
********************************/

//Header de Base.
//***************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <myconio.h>

#include "header/cadreDesign.h"
#include "header/installFlotsBleus.h"
#include "baseStructures.c"

void installation(void);

//Variables globales.
//*******************
int val_pos[4]={5, 75, 2, 24}; //Pour dessiner le cadre.

int main(void)
{
    int i;
        afficherCadre(RED, val_pos);

        //On vérifie que le fichier parametre.bin existe.
        //***********************************************
        if(fopen("parametre.bin", "r")==NULL)
        {
            installation();
        }

    getchar();
    return(0);
}

//Fonction pour installer le programme de base.
//*********************************************
void installation(void)
{
    afficherPartUne();
    afficherChampsPartUn(8);
    fichierPartUn();

    clrscr();
    afficherCadre(RED, val_pos);

    afficherPartDeux();
    afficherChampsPartDeux(4);
    fichierPartDeux();

    clrscr();
    afficherCadre(RED, val_pos);

    afficherFinInstallation();
}
