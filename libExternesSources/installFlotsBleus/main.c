#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct{
    char rue[50];
    char cp[10];
    char loc[30];
    char pays[20];
} adresse;

typedef struct{
    unsigned int aa;
    unsigned int mm;
    unsigned int jj;
} date;

typedef struct{
    unsigned int pa_nb_e;
    unsigned int pa_nb_c;
    unsigned int pa_nb_ch;
    unsigned int pa_nb_s;
    unsigned long int pa_no_cli;
    unsigned long int pa_no_fact;
    unsigned long int pa_no_sj;
    unsigned long int pa_no_su;
    unsigned long int pa_pa_d;
    unsigned long int pa_pa_f;
    date pa_date_jr;
    char pa_pasu[10];
    char pa_pass[10];
    char pa_nom[30];
    adresse pa_adresse;
    char pa_tel[20];
    char pa_tel2[20];
    char pa_email[50];
    char pa_www[50];
    char pa_rem[80];
} parametre;

void afficherTitre(void)
{
    gotoxy(27,4); printf("RENSEIGNEMENTS DU CAMPING");
    gotoxy(27,5); printf("*************************");
}

void afficherPartUne(void)
{
    afficherTitre();
    gotoxy(12,7); printf("Nom du camping:");
    gotoxy(12,9); printf("Rue et num\x82ro:");
    gotoxy(12,11); printf("Code postal:");
    gotoxy(12,13); printf("Localit\x82:");
    gotoxy(12,15); printf("Pays:");
    gotoxy(12,17); printf("Num\x82ro de t\202l\x82phone:");
    gotoxy(12,19); printf("Mot de passe (superviseur):");
    gotoxy(12,21); printf("Mot de passe (utilisateur):");
}

void afficherPartDeux(void)
{
    afficherTitre();
        // Passage de 8 (--> dim du champs) paramètres !
    gotoxy(12,7); printf("Num\x82ro secondaire:");
    gotoxy(12,9); printf("Adresse email:");
    gotoxy(12,11); printf("Site web:");
    gotoxy(12,13); printf("Remarques \x85 afficher en bas des factures:");
}

void afficherChampsPartUn(int dim)
{
    int i, j;

    for(j=0,i=7;j<dim;i+=2,j++) MYclrwin(40, i, 70, i);
}

void afficherChampsPartDeux(int dim)
{
    int i, j;

    for(j=0,i=7;j<dim-1;i+=2,j++) MYclrwin(40, i,70, i);
}

void fichierPartUn(void)
{
    //Variables.
    //**********
    FILE *ptr_file;
    parametre fiche;
    int i;

        //Ouverture du fichier.
        //*********************
        ptr_file=fopen("parametre.bin","wb");

        //Initialisation=>Nom.
        //********************
        for(i=0; i<30; i++) fiche.pa_nom[i]=' ';
        fiche.pa_nom[i-1]='\0';
        gotoxy(41,7); fflush(stdin);
        gets(fiche.pa_nom);

        //Initialisation=>Rue.
        //********************
        for(i=0; i<50; i++) fiche.pa_adresse.rue[i]=' ';
        fiche.pa_adresse.rue[i-1]='\0';
        gotoxy(41,9); fflush(stdin);
        gets(fiche.pa_adresse.rue);

        //Initialisation=>Code Postal.
        //****************************
        for(i=0; i<10; i++) fiche.pa_adresse.cp[i]=' ';
        fiche.pa_adresse.cp[i-1]='\0';
        gotoxy(41,11); fflush(stdin);
        gets(fiche.pa_adresse.cp);

        //Initialisation=>Code Localite.
        //******************************
        for(i=0; i<30; i++) fiche.pa_adresse.loc[i]=' ';
        fiche.pa_adresse.loc[i-1]='\0';
        gotoxy(41,13); fflush(stdin);
        gets(fiche.pa_adresse.loc);

        //Initialisation=>Pays.
        //*********************
        for(i=0; i<20; i++) fiche.pa_adresse.pays[i]=' ';
        fiche.pa_adresse.pays[i-1]='\0';
        gotoxy(41,15); fflush(stdin);
        gets(fiche.pa_adresse.pays);

        //Initialisation=>Telephone.
        //**************************
        for(i=0; i<20; i++) fiche.pa_tel[i]=' ';
        fiche.pa_tel[i-1]='\0';
        gotoxy(41,17); fflush(stdin);
        gets(fiche.pa_tel);

        //Initialisation=>mdp utilisateur.
        //********************************
        for(i=0; i<10; i++) fiche.pa_pasu[i]=' ';
        fiche.pa_pasu[i-1]='\0';
        gotoxy(41,19); fflush(stdin);
        gets(fiche.pa_pasu);

        //Initialisation=>mdp superviseur.
        //********************************
        for(i=0; i<10; i++) fiche.pa_pass[i]=' ';
        fiche.pa_pass[i-1]='\0';
        gotoxy(41,21); fflush(stdin);
        gets(fiche.pa_pass);

        //Ecriture dans le fichier + Fermeture.
        //*************************************
        fwrite(&fiche, sizeof(parametre), 1, ptr_file);
        fclose(ptr_file);
}

void fichierPartDeux(void)
{
    //Variables.
    //**********
    FILE *ptr_file;
    parametre fiche;
    int i;

        //Ouverture du fichier + lecture du fichier
        //afin de savoir ou on s'etait arreter.
        //*****************************************
        ptr_file=fopen("parametre.bin","r+b");
        fread(&fiche, sizeof(parametre), 1, ptr_file);

        //Initialisation=>Telephone n°2.
        //******************************
        for(i=0; i<20; i++) fiche.pa_nom[i]=' ';
        fiche.pa_nom[i-1]='\0';
        gotoxy(41,7); fflush(stdin);
        gets(fiche.pa_tel2);

        //Initialisation=>Email.
        //**********************
        for(i=0; i<50; i++) fiche.pa_nom[i]=' ';
        fiche.pa_nom[i-1]='\0';
        gotoxy(41,9); fflush(stdin);
        gets(fiche.pa_email);

        //Initialisation=>WWW.
        //********************
        for(i=0; i<50; i++) fiche.pa_nom[i]=' ';
        fiche.pa_nom[i-1]='\0';
        gotoxy(41,11); fflush(stdin);
        gets(fiche.pa_www);

        //Initialisation=>Remarques.
        //**************************
        for(i=0; i<80; i++) fiche.pa_nom[i]=' ';
        fiche.pa_nom[i-1]='\0';
        gotoxy(16,15); fflush(stdin);
        gets(fiche.pa_rem);

        //Ecriture + Fermeture du fichier.
        //********************************
        fseek(ptr_file, 0, SEEK_SET);
        fwrite(&fiche, sizeof(parametre), 1, ptr_file);
        fclose(ptr_file);
}

void afficherFinInstallation(void)
{
    //Variables.
    //**********
    int i;

        afficherTitre();
        gotoxy(10,9); printf("[");

        //Un petit effet visuel.
        //**********************
        for(i=(wherey()+1); i<70; i++)
        {
            printf("*");
            Sleep(10);
        }

        gotoxy(70,9); printf("]");
        gotoxy(10,11); printf("=> Installation termin\202e.");
}

