#define _POSIX_C_SOURCE 1
#include "Plateau.h"
#include "Coordonnee/Coordonnee.h"

int main(int argc, char const *argv[]) {

    printf("Création d'une grille de taille 8*8\n" );
    Plateau plateau=construction_Plateau(8);
    afficher_plateau(plateau);


    printf("Placer un pion (JOUEUR_1) sur les coordonées 2,3\n" );
    placer_Pion(plateau,JOUEUR_1,Coord(2,3));



    printf("Pour connaitre l'existance d'un pion à une Coordonnee (voir code): \n" );
    if(connaitre_Pion(plateau,Coord(2,3))==JOUEUR_1)
        printf("JOUEUR_1 sur 2,3\n" );

    afficher_plateau(plateau);


    printf("Placer des pions d'un autre du JOUEUR_2 autour d'un autre :\n");
    int x=2,y=3;
    for (size_t i = 0; i < 6; i++) {

        Coordonnee voisin=obtenir_voisin(Coord(x,y),i);
        /*
        i=0 en haut
        i=1 en haut à droite
        i=2 en à droite
        i=3 en bas à droite
        i=4 en bas
        i=5 en bas à gauche
        */
        placer_Pion(plateau,JOUEUR_2,voisin);

    }
    afficher_plateau(plateau);


    printf("Verification dees effets de bords\n" );
    for (size_t i = 0; i < 6; i++) {

        Coordonnee voisin=obtenir_voisin(Coord(7,4),i);
        placer_Pion(plateau,JOUEUR_2,voisin);

    }
    afficher_plateau(plateau);

    freed_Plateau( plateau);
    return 0;
}
