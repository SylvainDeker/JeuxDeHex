#define _POSIX_C_SOURCE 1
#include "Plateau.h"
#include "Coordonnee/Coordonnee.h"

int main(int argc, char const *argv[]) {

    printf("Création d'une grille de taille 8*8\n" );
    Plateau plateau=constructeur_plateau(8);
    freed_Plateau(plateau);
    return 0;
}
