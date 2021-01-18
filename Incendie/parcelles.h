#ifndef __PARCELLES__
#define __PARCELLES__

typedef struct t_parcelle t_parcelle;
struct t_parcelle
{
    char type[100];
    int x;
    int y;
};
typedef struct t_terrain t_terrain;
struct t_terrain
{
    int terrain[40][60];
};
void affichage_terrain(t_terrain terrain);
char couleur_aleatoire();
void terrain_aleatoire(t_terrain *terrain);
void AffichageAllegro(t_terrain terrain,int RT,int origin);
int gestion_feux(t_terrain terrain1, t_terrain *terrain2);
void gestion_t1(t_terrain *terrain1,t_terrain terrain2);
void fond_menu(int RT,int origin);
void affichage_nb_case(t_terrain terrain,int rep);
void menu_start(int RT,int origin);
void mode2_generation(t_terrain *terrain);
void mode2_clic(t_terrain *terrain);
int switch_menu();
int calcul_nb_arbre(t_terrain terrain);
void mode3(int nb_simu);
void mode4(int nb_simu);
#endif // __PARCELLES__
