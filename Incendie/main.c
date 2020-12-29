#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <allegro.h>
#include "parcelles.h"



int main(int argc, char *argv[])
{
    const int L = 40;
    const int C = 60;
    const int RT = 20;

    printf("Hello world!\n");
    t_parcelle parcelle = {"marron",1,1};
    t_terrain terrain;
    printf("\n%s",parcelle.type);

    terrain_aleatoire(&terrain);


    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    //creation de la fenetre d'affichagge Allegro
    int Ecran_X = RT*60;
    int Ecran_Y = RT*40;
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,Ecran_X,Ecran_Y,0,0) != 0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    AffichageAllegro(terrain);
    readkey();
    return 0;
}
END_OF_MAIN();
