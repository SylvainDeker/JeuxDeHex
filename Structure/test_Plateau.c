#define _POSIX_C_SOURCE 1
#include "Plateau.h"
#include "Coordonnee/Coordonnee.h"

int main(int argc, char const *argv[]) {

    printf("Création d'une grille de taille 8*8\n" );
    Plateau plateau=constructeur_plateau(8);

    insersion_plateau(plateau,Coord(1,5),JOUEUR_1);

    Coordonnee c=Coord(1,5);
    for (size_t i = 0; i < 6; i++) {
        insersion_plateau(plateau,Coord_voisin(c,i),JOUEUR_2);
    }

    afficher_plateau(plateau);
    freed_Plateau(plateau);
    return 0;
}
