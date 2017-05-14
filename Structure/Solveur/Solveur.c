/*!
   \file Soveur.c
   \brief
   \author Sylvain DEKER
   \date 14/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Solveur.h"

typedef struct _noeud{
    unsigned int nb_fils;
    Plateau plateau;
    struct _noeud ** fils;
}*Noeud;

struct _arbre_possibilites{
    Noeud sentinelle;
    // unsigned int nb_possibilite_gagnante_j1;
    // unsigned int nb_possibilite_gagnante_j2;
};

void feed_arbre_solveur_rec(Plateau p,Noeud nd,unsigned int possibilites,int joueur);

Noeud constructeur_noeud(unsigned int nb_fils){
    Noeud nd=(Noeud)malloc(sizeof(struct _noeud));
    nd->nb_fils=nb_fils;
    nd->fils=(Noeud*)malloc(sizeof(Noeud)*nb_fils);
    return nd;
}

Arbre_solveur constructeur_arbre_solveur(Plateau p){
    Arbre_solveur as=(Arbre_solveur)malloc(sizeof(struct _arbre_possibilites));
    unsigned int dim=Dimention_plateau(p);
    as->sentinelle=constructeur_noeud(dim*dim-(liste_taille(Historique_Joueur(Joueur1(p)))+liste_taille(Historique_Joueur(Joueur2(p)))) );
    feed_arbre_solveur_rec(p,as->sentinelle,dim*dim-(liste_taille(Historique_Joueur(Joueur1(p)))+liste_taille(Historique_Joueur(Joueur2(p)))),0);
    return as;
}

void feed_arbre_solveur_rec(Plateau p,Noeud nd,unsigned int possibilites,int joueur){
    if (!Existe_Gangnant(p)
        &&
        possibilites>0
    ) {
        unsigned int nb_fils=0;
        for (unsigned int i = 0; i < Dimention_plateau(p); i++) {
            for (unsigned int j = 0; j < Dimention_plateau(p); j++) {
                if(Case_Vide(p,Coord(i,j))){
                    nd->fils[nb_fils]=constructeur_noeud(possibilites);
                    nd->nb_fils=possibilites;
                    nd->fils[nb_fils]->plateau=copie_de_plateau(p);
                    if(joueur==1){
                        poser_un_pion(nd->fils[nb_fils]->plateau,Joueur1(nd->fils[nb_fils]->plateau),Coord(i,j));
                        joueur=0;
                    }
                    else{
                        poser_un_pion(nd->fils[nb_fils]->plateau,Joueur2(nd->fils[nb_fils]->plateau),Coord(i,j));
                        joueur=1;
                    }
                    feed_arbre_solveur_rec(nd->fils[nb_fils]->plateau,nd->fils[nb_fils],possibilites-1,joueur);

                    nb_fils++;
                }
            }
        }
    }
}


Plateau copie_de_plateau(Plateau p){

    Joueur j1=contructeur_Joueur();
    Joueur j2=contructeur_Joueur();
    Plateau pnew=constructeur_plateau(Dimention_plateau(p),j1,j2);

    ListeItr itr_historique_joueur1,itr_historique_joueur2;

    itr_historique_joueur1=constructeur_liste_iterateur(Historique_Joueur(Joueur1(p)),FIFO);
    itr_historique_joueur2=constructeur_liste_iterateur(Historique_Joueur(Joueur2(p)),FIFO);

    start_liste_iterateur(itr_historique_joueur1);
    start_liste_iterateur(itr_historique_joueur2);
    Case cas;
    Coordonnee cd;

    while(!fin_liste_iterateur(itr_historique_joueur1) || !fin_liste_iterateur(itr_historique_joueur2) ){

        if(!fin_liste_iterateur(itr_historique_joueur1)){
            cas=(Case)liste_iterateur_courant(itr_historique_joueur1);
            cd=Coordonne_de_la_Case(cas);
            poser_un_pion(pnew,j1,cd);
            suivant_liste_iterateur(itr_historique_joueur1);
        }
        if(!fin_liste_iterateur(itr_historique_joueur2)){
            cas=(Case)liste_iterateur_courant(itr_historique_joueur2);
            cd=Coordonne_de_la_Case(cas);
            poser_un_pion(pnew,j2,cd);
            suivant_liste_iterateur(itr_historique_joueur2);

        }
    }
    freed_liste_iterateur(itr_historique_joueur1);
    freed_liste_iterateur(itr_historique_joueur2);


    return pnew;

}





void affichage_plateau(Plateau p){
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



void affichage_as_rec(Noeud nd){
    affichage_plateau(nd->plateau);
    for (unsigned int i = 0; i < 1; i++) {
        affichage_as_rec(nd->fils[i]);
    }
}
void affichage_as(Arbre_solveur as){
    for (unsigned int i = 0; i < as->sentinelle->nb_fils; i++) {
        affichage_as_rec(as->sentinelle->fils[i]);
    }

}
