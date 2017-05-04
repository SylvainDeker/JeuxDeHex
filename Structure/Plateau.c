/*!
   \file Plateau.c
   \brief Plateau.c
   \author Sylvain DEKER
   \date 1/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Plateau.h"


typedef struct _groupe{
    bool extremite1_atteind;
    bool extremite2_atteind;
}*Groupe;

typedef struct _case{
    Pion pion;
    Groupe groupe;
}*Case;


struct _plateau{
    unsigned int dim;//dimention
    Case**c;
    Groupe*Joueur1;//liste des groupes du Joueur 1
    unsigned int nb_grp_joueur_1;
    Groupe*Joueur2;//listes des groupes du Joueur 2
    unsigned int nb_grp_joueur_2;

};

/////////////////////////FONCTIONS PRIVES////////////////////////////
Case construction_case(){
    Case new = (Case)malloc(sizeof(struct _case));
    new->pion=VIDE;
    return new;
}
/////////////////////////////FONCTIONS PUBLIQUES////////////////////////
Plateau constructeur_plateau(unsigned int dimention){
    Plateau p=(Plateau)malloc(sizeof(struct _plateau));
    p->c=(Case**)malloc(sizeof(Case*)*dimention);

    for (unsigned int i = 0; i < dimention; i++) {
        p->c[i]=(Case*)malloc(sizeof(Case*)*dimention);
    }
    for (unsigned int i = 0; i < dimention; i++) {
        for (unsigned int j = 0; j < dimention; j++) {
            p->c[i][j]= construction_case();
        }
    }
    p->dim=dimention;
    p->nb_grp_joueur_1=0;
    p->nb_grp_joueur_2=0;

    return p;
}


void freed_Plateau(Plateau p){
    for (unsigned int i = 0; i < p->dim; i++) {
        for (unsigned int j = 0; j < p->dim; j++) {
            free(p->c[i][j]);
        }
    }
    for (unsigned int i = 0; i < p->dim; i++) {
        free(p->c[i]);
    }
    free(p->c);
    for (unsigned int i = 0; i < p->nb_grp_joueur_1; i++) {
        free(p->Joueur1[i]);
    }
    for (unsigned int i = 0; i < p->nb_grp_joueur_2; i++) {
        free(p->Joueur2[i]);
    }

    free(p);
}
