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

#endif // __PARCELLES__
