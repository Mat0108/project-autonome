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

void AffichageAllegro(t_terrain terrain)
{
    int RT = 20;
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
                image=load_bitmap("image/terre.bmp",NULL);
                blit(image,screen,0,0,RT*i,RT*j,image->w, image->h);
                break;
            case 1 :
                image=load_bitmap("image/arbre.bmp",NULL);
                blit(image,screen,0,0,RT*i,RT*j,image->w, image->h);
                //rectfill(screen,RT*i,RT*j,RT*(i+1),RT*(j+1),makecol(81,116,63));
                break;
            case 2 :
                image=load_bitmap("image/eau.bmp",NULL);
                blit(image,screen,0,0,RT*i,RT*j,image->w, image->h);
                break;
            case 3 :
                image=load_bitmap("image/feu.bmp",NULL);
                blit(image,screen,0,0,RT*i,RT*j,image->w, image->h);
                //rectfill(screen,RT*i,RT*j,RT*(i+1),RT*(j+1),makecol(255,0,0));
                break;
            case 4 :
                image=load_bitmap("image/cendres.bmp",NULL);
                blit(image,screen,0,0,RT*i,RT*j,image->w, image->h);
                break;
            case 5 :
                 image=load_bitmap("image/cendres eteintes.bmp",NULL);
                blit(image,screen,0,0,RT*i,RT*j,image->w, image->h);
                break;
            }
        }
    }
}
