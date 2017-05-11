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

    printf("======================TEST : Coordonnee_case(){ ==========================\n" );

    // Case c1=TEMPORAIRE_poser_un_pion(p,patrick,Coord(2,3));
    // Case c2=TEMPORAIRE_poser_un_pion(p,patrick,Coord(2,5));
    //
    //
    // printf("%d,%d\n",Coordonnee_Case(c1).x, Coordonnee_Case(c1).y );
    //
    //
    //
    //
    // fusionner_groupe(Groupe_de_la_Case(c1),Groupe_de_la_Case(c2));
    // bilan(p);
    printf("======================TEST : Poser_un_pion(){ ==========================\n" );

    srand(200);
    for (size_t i = 0; i < 75; i++) {
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


    printf("%d",rand()%12);

    // printf("======================TEST : voisin_etant_du_joueur(){ ==========================\n" );
    // Liste l=constructeur_liste();
    // voisin_etant_du_joueur(p,patrick,Coord(2,3),l);
    //
    // while(!liste_vide(l)){
    //     printf("%p\n",retirer_liste(l,"listemode") );
    // }
    // freed_liste(l);




    // afficher_plateau(p);

    freed_all(p);
    return 0;
}
