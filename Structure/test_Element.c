/*!
   \file test_Element.c
   \brief FICHIER DE TEST Structure de donnée des élements de base du jeux, plateau, pions etc..
   \author Sylvain DEKER
   \date 30/04/2017
*/
#define _POSIX_C_SOURCE 1
#include "Element.h"


int main(int argc, char const *argv[]) {
    unsigned int taille_plateau=5;
    /*Création du constructeur*/
    Jeux new_game = Constructeur_jeux(taille_plateau);

    placer_pion_jeux(new_game,JOUEUR1,2,3);
    placer_pion_jeux(new_game,JOUEUR1,2,4);



    /*Affichage dans le terminal*/
    afficher_plateaux(new_game);
    /*Liberation de la mémoire*/
    freed_jeux(new_game,taille_plateau);
    return 0;
}
