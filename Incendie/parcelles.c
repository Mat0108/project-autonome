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
    char couleur[20][6] = {"Terre","Arbre","Eau","Feu","Cendres","Cendres �teintes"};
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
                rectfill(screen,RT*(j+origin),RT*i,RT*(j+1+origin),RT*(i+1),makecol(77, 79, 84)); //cendres �teintes
                break;
            }
        }
    }
}

int gestion_feux(t_terrain terrain1, t_terrain *terrain2)
{
    int i,j;
    int xi[8] = {-1,-1,-1,0,0,1,1,1};
    int yi[8] = {-1,0,1,-1,1,-1,0,1};
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

void fond_menu(int RT,int origin)
{
     rectfill(screen,0,0,RT*origin,RT*40,makecol(70,70, 70));
     rectfill(screen,RT*origin,0,RT*origin-0.05,RT*40,makecol(1, 1, 1));
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
    int origin = 15*3;
    fond_menu(14,10);
    textprintf_ex(screen,font,10,origin,makecol(255,255,255),-1,"Terre : %-3d",nb_terre);
    textprintf_ex(screen,font,74,origin+10,makecol(255,255,255),-1,"%-5.2f %c",nb_terre/24.0,a);

    textprintf_ex(screen,font,10,origin+50,makecol(255,255,255),-1,"Arbre : %-3d",nb_arbre);
    textprintf_ex(screen,font,74,origin+60,makecol(255,255,255),-1,"%-5.2f %c",nb_arbre/24.0,a);

    textprintf_ex(screen,font,10,origin+100,makecol(255,255,255),-1,"Eau : %-3d",nb_eau);
    textprintf_ex(screen,font,58,origin+110,makecol(255,255,255),-1,"%-5.2f %c",nb_eau/24.0,a);

    textprintf_ex(screen,font,10,origin+150,makecol(255,255,255),-1,"Feu : %-3d",nb_feu);
    textprintf_ex(screen,font,58,origin+160,makecol(255,255,255),-1,"%-5.2f %c",nb_feu/24.0,a);

    textprintf_ex(screen,font,10,origin+200,makecol(255,255,255),-1,"Cendres : ");
    textprintf_ex(screen,font,19,origin+210,makecol(255,255,255),-1,"%-4d %-5.2f %c",nb_cendres, nb_cendres/24.0,a);

    textprintf_ex(screen,font,10,origin+250,makecol(255,255,255),-1,"C. eteintes: ");
    textprintf_ex(screen,font,12,origin+260,makecol(255,255,255),-1," %-4d %-5.2f %c",nb_cendres_eteintes, nb_cendres_eteintes/24.0,a);
}
void menu_start(int RT,int origin)
{
    char adress[100];
    BITMAP *image;
    rectfill(screen,0,0,RT*(origin+60),RT*40,makecol(70,70, 70));
    sprintf(adress,"image/menu_0.bmp");
    image = load_bitmap(adress,NULL);
    blit(image,screen,0,0,90,128,image->w, image->h);
    while (!key[KEY_SPACE]){}
}

void mode1_generation(t_terrain *terrain)
{
    int i,j;
    srand(time(NULL));
    for (i=0;i<40;i++)
    {
        for (j=0;j<60;j++)
        {
            terrain->terrain[i][j] = rand()%3;
        }
    }
}
void mode1_clic(t_terrain *terrain)
{
    int condition = 1;
    show_mouse(screen);
    while (condition == 1)
    {
        if (mouse_b & 1 || mouse_b & 2)
        {
            terrain->terrain[mouse_y/14][mouse_x/14-10] = 3;
            condition = 0;
        }
    }
    AffichageAllegro(*terrain,14,10);
}


int switch_menu()
{
    char adress[100];
    BITMAP *image;
    rectfill(screen,0,0,14*(10+60),14*40,makecol(70,70, 70));
    sprintf(adress,"image/menu_1.bmp");
    image = load_bitmap(adress,NULL);
    blit(image,screen,0,0,45,100,image->w, image->h);
    sprintf(adress,"image/menu_2.bmp");
    image = load_bitmap(adress,NULL);
    blit(image,screen,0,0,245*3-200,100,image->w, image->h);
    sprintf(adress,"image/menu_3.bmp");
    image = load_bitmap(adress,NULL);
    blit(image,screen,0,0,45,300,image->w, image->h);
    sprintf(adress,"image/menu_4.bmp");
    image = load_bitmap(adress,NULL);
    blit(image,screen,0,0,245*3-200,300,image->w, image->h);

    int condition = 1;
    show_mouse(screen);

    while (condition == 1)
    {
        textprintf_ex(screen,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",mouse_x,mouse_y);

        if ((mouse_b & 1 || mouse_b & 2) && mouse_x < 480 && mouse_y<280)
        {
            return 1;
            condition = 0;
        }
        if ((mouse_b & 1 || mouse_b & 2) && mouse_x > 480 && mouse_y<280)
        {
            return 2;
            condition = 0;
        }
        if ((mouse_b & 1 || mouse_b & 2) && mouse_x < 480 && mouse_y>280)
        {
            return 3;
            condition = 0;
        }
        if ((mouse_b & 1 || mouse_b & 2) && mouse_x > 480 && mouse_y>280)
        {
            return 4;
            condition = 0;
        }
    }
}
