#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro.h>
#include <time.h>
#include <process.h>
#include <winalleg.h>
#include <windows.h>
#include "parcelles.h"



int main(int argc, char *argv[])
{
    const int L = 40;
    const int C = 60;
    const int RT = 14;
    const int origin  = 10;

    int nb_feu = 100;
    int rep = 1;
    int rep2 = 1;

    t_parcelle parcelle = {"marron",1,1};
    t_terrain terrain;
    t_terrain terrain2;

    terrain_aleatoire(&terrain);


    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    //creation de la fenetre d'affichagge Allegro
    int Ecran_X = RT*(60+origin);
    int Ecran_Y = RT*40;
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,Ecran_X,Ecran_Y,0,0) != 0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    printf("\n      Terre     |    Arbre     |      Eau     |      Feu     |   Cendres    |  C.eteintes");
    affichage_nb_case(terrain,rep2);
    AffichageAllegro(terrain,RT,origin);
    while (rep == 1)
    {
        rep2++;
        if (nb_feu == 0) rep = 0;
        nb_feu = gestion_feux(terrain,&terrain2);
        gestion_t1(&terrain,terrain2);
        Sleep(3000);
        AffichageAllegro(terrain,RT,origin);
        affichage_nb_case(terrain,rep2);
    }

    readkey();
    return 0;
}
END_OF_MAIN();
