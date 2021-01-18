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

    t_terrain terrain;
    t_terrain terrain2;


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
    fond_menu(RT,origin);

    menu_start(RT,origin);
    srand(time(NULL));
    int choix_menu = switch_menu();
    //géneration du terrrain en fonction du mode
    if (choix_menu == 1) terrain_aleatoire(&terrain);
    if (choix_menu == 2)mode2_generation(&terrain);
    //afifchage du terrain et initialisation du tableau de stats
    if (choix_menu == 1 || choix_menu == 2)
    {
        printf("\n      Terre     |    Arbre     |      Eau     |      Feu     |   Cendres    |  C.eteintes");
        affichage_nb_case(terrain,rep2);
        AffichageAllegro(terrain,RT,origin);
    }
    //choix de la case a mettre en feu
    if (choix_menu == 2)mode2_clic(&terrain);
    //modifications des données
    if (choix_menu == 1 || choix_menu == 2)
    {
        while (rep == 1 )
        {
            rep2++;
            if (nb_feu == 0) rep = 0;
            nb_feu = gestion_feux(terrain,&terrain2);
            gestion_t1(&terrain,terrain2);
            Sleep(1000);
            AffichageAllegro(terrain,RT,origin);
            affichage_nb_case(terrain,rep2);
        }
    }
    //simimulations
    if (choix_menu == 3)mode3(100);
    if (choix_menu == 4)mode4(10);
    while (!key[KEY_ESC])
    readkey();
    return 0;
}
END_OF_MAIN();
