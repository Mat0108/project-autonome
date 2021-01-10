#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include "parcelles.h"



void affichage_terrain(t_terrain terrain)
{
    for(int i=0;i<40;i++)
    {
        printf("\n ligne %d : ",i);
        for(int j=0;j<60;j++)
        {
            printf("%d",terrain.terrain[i][j]);
        }
    }
}

char couleur_aleatoire()
{
    char couleur[20][6] = {"Terre","Arbre","Eau","Feu","Cendres","Cendres éteintes"};
    srand(time(NULL));
    int x = rand()%6;
    printf("\n%d",x);
    printf("\n%s",couleur[x]);
    return couleur[x];
}

void terrain_aleatoire(t_terrain *terrain)
{
    int i,j;
    srand(time(NULL));
    for (i=0;i<40;i++)
    {
        for (j=0;j<60;j++)
        {
            terrain->terrain[i][j] = rand()%6;
        }
    }
}

void AffichageAllegro(t_terrain terrain,int RT,int origin)
{
    int i,j;
    for (i = 0;i<40;i++)
    {
        for (j=0;j<60;j++)
        {
            switch(terrain.terrain[i][j])
            {
            case 0 :
                rectfill(screen,RT*(j+origin),RT*i,RT*(j+1+origin),RT*(i+1),makecol(106,61,51)); //terre
                break;
            case 1 :
                rectfill(screen,RT*(j+origin),RT*i,RT*(j+1+origin),RT*(i+1),makecol(81,116,63)); //arbre
                break;
            case 2 :
                rectfill(screen,RT*(j+origin),RT*i,RT*(j+1+origin),RT*(i+1),makecol(40,67,141)); //eau
                break;
            case 3 :
                rectfill(screen,RT*(j+origin),RT*i,RT*(j+1+origin),RT*(i+1),makecol(255,0,0)); //feu
                break;
            case 4 :
                rectfill(screen,RT*(j+origin),RT*i,RT*(j+1+origin),RT*(i+1),makecol(159, 161, 165)); //cendres
                 break;
            case 5 :
                rectfill(screen,RT*(j+origin),RT*i,RT*(j+1+origin),RT*(i+1),makecol(77, 79, 84)); //cendres éteintes
                break;
            }
        }
    }
}

int gestion_feux(t_terrain terrain1, t_terrain *terrain2)
{
    int i,j;
    int xi[8] = {-1,-1,-1,0,0,1,1,1};
    int yi[8] = {-1,0,1,-1,1,-1,0,-1};
    int nb_feu = 0;
    for (i = 0;i<40;i++)
    {
        for (j=0;j<60;j++)
        {
            terrain2->terrain[i][j] = terrain1.terrain[i][j];
            if (terrain1.terrain[i][j] == 1){
                for (int k=0;k<8;k++){
                    if (terrain1.terrain[i-xi[k]][j-yi[k]] == 3) terrain2->terrain[i][j] = 3;}}
            if (terrain1.terrain[i][j] == 3) terrain2->terrain[i][j] = 4;
            if (terrain1.terrain[i][j] == 4) terrain2->terrain[i][j]= 5;
            if (terrain2->terrain[i][j]== 3) nb_feu++;
        }
    }
    return nb_feu;
}

void gestion_t1(t_terrain *terrain1,t_terrain terrain2)
{
    int i,j;
    for (i=0;i<40;i++)
        {
        for(j=0;j<60;j++)
        {
            terrain1->terrain[i][j] = terrain2.terrain[i][j];
        }

    }
}

void affichage_nb_case(t_terrain terrain,int rep)
{
    int nb_terre = 0;
    int nb_arbre = 0;
    int nb_eau = 0;
    int nb_feu = 0;
    int nb_cendres = 0;
    int nb_cendres_eteintes = 0;
    int i,j;
    for (i = 0;i<40;i++)
    {
        for (j=0;j<60;j++)
        {
            switch(terrain.terrain[i][j])
            {
            case 0 :
                nb_terre++;
                break;
            case 1 :
                nb_arbre++;
                break;
            case 2 :
                nb_eau++;
                break;
            case 3 :
                nb_feu++;
                break;
            case 4 :
                nb_cendres++;
                break;
            case 5 :
                nb_cendres_eteintes++;
                break;
            }
        }
    }
    char a;
    a = '%';
    printf("\n%2d %4d %5.2f%c  | %4d %5.2f%c  | %4d %5.2f%c  ",rep,nb_terre, nb_terre/24.0,a,nb_arbre, nb_arbre/24.0,a,nb_eau,nb_eau/24.0,a);
    printf("| %4d %5.2f%c  | %4d %5.2f%c  | %4d %5.2f%c",nb_feu,nb_feu/24.0,a,nb_cendres,nb_cendres/24.0,a,nb_cendres_eteintes,nb_cendres_eteintes/24.0,a);
}

