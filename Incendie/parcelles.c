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
        printf("\n");
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

            int x = rand()%6;
            terrain->terrain[i][j] = x;
        }
    }

}

void AffichageAllegro(t_terrain terrain,int RT)
{
    BITMAP *image;
    int i,j;
    char adress[100];
    for (i = 0;i<60;i++)
    {
        for (j=0;j<40;j++)
        {
            switch(terrain.terrain[i][j])
            {
            case 0 :
                rectfill(screen,RT*i,RT*j,RT*(i+1),RT*(j+1),makecol(106,61,51)); //terre
                break;
            case 1 :
                rectfill(screen,RT*i,RT*j,RT*(i+1),RT*(j+1),makecol(81,116,63)); //arbre
                break;
            case 2 :
                rectfill(screen,RT*i,RT*j,RT*(i+1),RT*(j+1),makecol(40,67,141)); //eau
                break;
            case 3 :
                rectfill(screen,RT*i,RT*j,RT*(i+1),RT*(j+1),makecol(255,0,0)); //feu
                break;
            case 4 :
                rectfill(screen,RT*i,RT*j,RT*(i+1),RT*(j+1),makecol(159, 161, 165)); //cendres
                 break;
            case 5 :
                rectfill(screen,RT*i,RT*j,RT*(i+1),RT*(j+1),makecol(77, 79, 84)); //cendres éteintes
                break;
            }
        }
    }
}

void gestion_feux(t_terrain terrain1, t_terrain *terrain2)
{
    int i,j;
    for (i = 0;i<60;i++)
    {
        for (j=0;j<40;j++)
        {
            switch(terrain1.terrain[i][j])
            {
            case 3:
                terrain2->terrain[i][j] = 4;
                break;
            case 4:
                terrain2->terrain[i][j] = 5;
                break;
            case 1:
                if (terrain1.terrain[i-1][j-1] == 3 || terrain1.terrain[i][j-1] == 3 || terrain1.terrain[i+i][j-1] == 3 || terrain1.terrain[i-1][j] == 3 || terrain1.terrain[i+1][j] == 3 || terrain1.terrain[i-1][j+1] == 3 || terrain1.terrain[i][j+1] == 3  || terrain1.terrain[i+1][j+1] == 3)
                {
                    terrain2->terrain[i][j] == 3;
                    break;
                }
            default:
                terrain2->terrain[i][j] = terrain1.terrain[i][j];
                break;
            }
        }
    }
}

