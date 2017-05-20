/*!
   \file Solveur.c
   \brief
   \author Sylvain DEKER
   \date 14/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Solveur.h"

struct _solveur{
    Arbre_solveur as;
    Noeud noeud_courant;
    Plateau plateau_reference;
    int joueur_gagnant;//1 ou 2

};


Solveur constructeur_solveur(Plateau plateau_reference,Arbre_solveur as,int joueur_gagnant){

    Solveur sv =(Solveur) malloc(sizeof(struct _solveur));
    sv->as=constructeur_arbre_solveur(plateau_reference);
    application_minmax(sv->as);
    sv->plateau_reference=plateau_reference;
    sv->noeud_courant=sentinelle_arbre_solveur(sv->as);
    sv->joueur_gagnant=joueur_gagnant;

    return sv;
}


Coordonnee obtenir_coordonnee_prochain_coup_gagnant(Solveur sv){
    Noeud * tab=tableau_fils_noeud(sv->noeud_courant);
    if(sv->joueur_gagnant==1){

        for (unsigned int i = 0; i < nb_fils_noeud(sv->noeud_courant); i++) {
            printf("%d,%d\n",poids_j1_noeud(tab[i]),poids_j2_noeud(tab[i]) );

        }
    }


}
