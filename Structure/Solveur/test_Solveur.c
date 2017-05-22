
/*!
   \file test_Arbre.c
   \brief test_Arbre.c
   \author Sylvain DEKER
   \date 13/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Solveur.h"

#define TAILLE_PLAT 3

/// T = 9    1
// T = 16    8
// T = 25   18
//T=36      32
//T=49      44
//T=64      56



void afficher_plateau(Plateau p);
void bilan(Plateau p);

int main(int argc, char const *argv[]) {

    Joueur patrick=contructeur_Joueur();
    Joueur robert=contructeur_Joueur();
    Plateau p=constructeur_plateau(TAILLE_PLAT,patrick,robert);

    srand(20);
    int x=0,y=0;

    for (size_t i = 0; i < 2; i++) {
    // while(!Existe_Gangnant(p)){

        while (!Case_Vide(p,Coord(x,y)) ){
            x=rand()%Dimention_plateau(p);
            y=rand()%Dimention_plateau(p);
        }
        poser_un_pion(p, Joueur1(p), Coord(x,y) );
        while (!Case_Vide(p,Coord(x,y)) ){
            x=rand()%Dimention_plateau(p);
            y=rand()%Dimention_plateau(p);
        }
        if(!Existe_Gangnant(p))
            poser_un_pion(p,Joueur2(p),Coord(x,y));

        afficher_plateau(p);
        // bilan(p);

    }

    printf("=============================TEST DE copie_plus_un_pion()=================================\n" );
    // Plateau pnew=copie_de_plateau(p);
    //
    // freed_all(p);
    // afficher_plateau(pnew);
    // bilan(pnew);
    //freed_all(pnew);

    printf("=============================TEST DE constructeur_arbre_solveur()=================================\n" );

    afficher_plateau(p);

    //Init
    Arbre_solveur as =constructeur_arbre_solveur(p);
    Solveur slv=constructeur_solveur(p,as,1);

    //Joueir 1
    Coordonnee cd=obtenir_coordonnee_prochain_coup_gagnant(slv);
    printf("Prochain coup: %d, %d\n",cd.x,cd.y );
    poser_un_pion(p, Joueur2(p), cd );
    afficher_plateau(p);
    printf("gagnant : %p\n",Existe_Gangnant(p) );

    //Joueur2
    poser_un_pion(p, Joueur1(p), Coord(1,1) );
    prochain_coup_adversaire(slv,Coord(1,1));
    afficher_plateau(p);
    printf("gagnant : %p\n",Existe_Gangnant(p) );

    //Joueur1

    cd=obtenir_coordonnee_prochain_coup_gagnant(slv);
    printf("Prochain coup: %d, %d\n",cd.x,cd.y );
    poser_un_pion(p, Joueur2(p), cd );
    afficher_plateau(p);
    printf("gagnant : %p\n",Existe_Gangnant(p) );



    // afficher_plateau(p);
    freed_arbre_solveur(as);
    freed_solveur(slv);
    freed_all(p);


    return 0;
}




//Tests !
/*
                Mur 1
                Joueur 0
    \ 1 \ 1 \ o \ o \ o \ o \ o \ o \
      \ o \ 1 \ o \ o \ o \ o \ 1 \ 1 \
        \ 1 \ o \ o \ 1 \ 1 \ 1 \ 1 \ o \
          \ 1 \ o \ . \ 1 \ 1 \ o \ o \ o \     Mur2
Mur1        \ 1 \ . \ 1 \ o \ . \ o \ o \ o \   Joueur 1
Joueur 1      \ 1 \ 1 \ 1 \ o \ o \ . \ . \ o \
                \ o \ 1 \ 1 \ . \ o \ 1 \ 1 \ 1 \
                  \ 1 \ o \ o \ 1 \ o \ 1 \ . \ 1 \
                                Mur 2
                                joueur 0
*/


void afficher_plateau(Plateau p){
    assert(p);
    printf("================================================\n" );
    for (int i = 0; i < Dimention_plateau(p); i++) {
        for (size_t h = 0; h < i; h++) {
            printf("  " );
        }
        for (int j = 0; j < Dimention_plateau(p); j++) {
            if(!Case_Vide(p,Coord(i,j))){
                if(Joueur_du_groupe( Groupe_de_la_Case( Case_de_la_Coordonnee(p,Coord(i,j)) ) )==Joueur1(p))
                    printf("\\ o " );
                else
                    printf("\\ 1 " );
            }
            else printf("\\ . " );
        }
        printf("\\\n" );
    }
    printf("================================================\n" );
}






void bilan(Plateau p){
    ListeItr itr_grp,itr_case;


    printf("joueur 0\n");
    itr_grp=constructeur_liste_iterateur(Liste_Groupe_du_Joueur(Joueur1(p)),FIFO);
    for(start_liste_iterateur(itr_grp);!fin_liste_iterateur(itr_grp);suivant_liste_iterateur(itr_grp)){

            Groupe g=(Groupe)liste_iterateur_courant(itr_grp);
            printf("Groupe: %p  ",g );
            if(Groupe_co_au_mur1(g))printf("Mur1 ");
            if(Groupe_co_au_mur2(g))printf("Mur2 ");
            printf(": ");
        itr_case=constructeur_liste_iterateur(Liste_Case_du_Groupe(g),FIFO);
        for(start_liste_iterateur(itr_case);!fin_liste_iterateur(itr_case);suivant_liste_iterateur(itr_case)){

            Case ca=(Case)liste_iterateur_courant(itr_case);
            Coordonnee co = Coordonne_de_la_Case(ca);
            printf("\t(%d,%d)",co.x,co.y );

        }
        printf("\n");
        freed_liste_iterateur(itr_case);
    }
    freed_liste_iterateur(itr_grp);
    printf("---------------\n" );

    printf("joueur 1\n");
    itr_grp=constructeur_liste_iterateur(Liste_Groupe_du_Joueur(Joueur2(p)),FIFO);
    for(start_liste_iterateur(itr_grp);!fin_liste_iterateur(itr_grp);suivant_liste_iterateur(itr_grp)){

            Groupe g=(Groupe)liste_iterateur_courant(itr_grp);
            printf("Groupe: %p  ",g );
            if(Groupe_co_au_mur1(g))printf("Mur1 ");
            if(Groupe_co_au_mur2(g))printf("Mur2 ");
            printf(": ");
        itr_case=constructeur_liste_iterateur(Liste_Case_du_Groupe(g),FIFO);
        for(start_liste_iterateur(itr_case);!fin_liste_iterateur(itr_case);suivant_liste_iterateur(itr_case)){

            Case ca=(Case)liste_iterateur_courant(itr_case);
            Coordonnee co = Coordonne_de_la_Case(ca);
            printf("\t(%d,%d)",co.x,co.y );

        }
        printf("\n");
        freed_liste_iterateur(itr_case);
    }
    freed_liste_iterateur(itr_grp);
    printf("---------------\n" );

    if(Existe_Gangnant(p))printf("Joueur gagnant : %p\n",Existe_Gangnant(p) );




    printf("Historique joueur 0\n" );
    ListeItr itr_histo;
    itr_histo=constructeur_liste_iterateur(Historique_Joueur(Joueur1(p)),FIFO);
    for(start_liste_iterateur(itr_histo);!fin_liste_iterateur(itr_histo);suivant_liste_iterateur(itr_histo)){

        Case cas=(Case)liste_iterateur_courant(itr_histo);
        Coordonnee cd = Coordonne_de_la_Case(cas);
        printf("(%d,%d) ",cd.x,cd.y );

    }
    printf("\n");
    freed_liste_iterateur(itr_histo);
    printf("Historique joueur 1\n" );
    itr_histo=constructeur_liste_iterateur(Historique_Joueur(Joueur2(p)),FIFO);
    for(start_liste_iterateur(itr_histo);!fin_liste_iterateur(itr_histo);suivant_liste_iterateur(itr_histo)){

        Case cas=(Case)liste_iterateur_courant(itr_histo);
        Coordonnee cd = Coordonne_de_la_Case(cas);
        printf("(%d,%d) ",cd.x,cd.y );

    }
    printf("\n");
    freed_liste_iterateur(itr_histo);

}
