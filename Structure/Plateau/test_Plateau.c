/*!
   \file test_Plateau.c
   \brief test_Plateau.c
   \author Sylvain DEKER
   \date 1/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Plateau.h"

#define TAILLE_PLAT 8

int main(int argc, char const *argv[]) {

    printf("======================TEST : contructeur_Joueur(){ ==========================\n" );
    Joueur patrick=contructeur_Joueur();
    Joueur robert=contructeur_Joueur();



    printf("======================TEST : contructeur_plateu(){ ==========================\n" );
    Plateau p=constructeur_plateau(TAILLE_PLAT,patrick,robert);


    printf("======================TEST : Poser_un_pion(){ ==========================\n" );

    srand(3);
    while(!Existe_Gangnant(p)){

        int x=rand()%8;
        int y=rand()%8;
        if(check_case_vide(p,Coord(x,y)))
            poser_un_pion(p,patrick,Coord(x,y));
        x=rand()%8;
        y=rand()%8;
        if(check_case_vide(p,Coord(x,y)))
            poser_un_pion(p,robert,Coord(x,y));
        afficher_plateau(p);
        bilan(p);
    }





    freed_all(p);
    return 0;
}
