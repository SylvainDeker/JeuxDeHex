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
    Case**cellule;
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

Groupe construction_groupe(){
    Groupe g=(Groupe)malloc(sizeof(struct _case) );
    g->extremite1_atteind=false;
    g->extremite2_atteind=false;
    return g;
}
/////////////////////////////FONCTIONS PUBLIQUES////////////////////////
Plateau constructeur_plateau(unsigned int dimention){
    Plateau p=(Plateau)malloc(sizeof(struct _plateau));
    p->cellule=(Case**)malloc(sizeof(Case*)*dimention);

    for (unsigned int i = 0; i < dimention; i++) {
        p->cellule[i]=(Case*)malloc(sizeof(Case*)*dimention);
    }
    for (unsigned int i = 0; i < dimention; i++) {
        for (unsigned int j = 0; j < dimention; j++) {
            p->cellule[i][j]= construction_case();
        }
    }
    p->dim=dimention;
    p->nb_grp_joueur_1=0;
    p->nb_grp_joueur_2=0;

    return p;
}

bool recherche_proximite(Plateau p,Coordonnee in,Pion pion,Coordonnee *out){
    int i=0;
    bool found=false;
    while(i<6&&!found){
        *out=Coord_voisin(in,i);
        if(out->x>=0&&out->x<p->dim&&out->y>=0&&out->y<p->dim){

            if( p->cellule[out->x][out->y]->pion==pion ){
                found=true;
            }
        }
        i++;
    }
    return found;
}

Plateau insersion_plateau(Plateau p,Coordonnee c,Pion pion){
    assert(c.x>=0  &&  c.x<p->dim  &&  c.y>=0  &&  c.y<p->dim);
    assert(p->cellule[c.x][c.y]->pion==VIDE);
    assert(pion== JOUEUR_1 || pion == JOUEUR_2);

    p->cellule[c.x][c.y]->pion=pion;
    Coordonnee n;
    recherche_proximite(p,c,pion,&n);

    if(recherche_proximite(p,c,pion,&n)){
        // if(pion==JOUEUR_1){
        //     ///Seconnecter au groupe de l'autr
        // }
        // if(pion==JOUEUR_2){
        //     ///Se connecter au groupe correspondant;
        // }
        printf("Recherche de proximite trouve\n");
    }
    else{
        Groupe new=construction_groupe();
        if(pion==JOUEUR_1){
            (p->nb_grp_joueur_1)++;
            p->Joueur1=realloc(p->Joueur1,sizeof(Groupe)*p->nb_grp_joueur_1);
            p->Joueur1[p->nb_grp_joueur_1-1]=new;
        }
        if(pion==JOUEUR_2){
            (p->nb_grp_joueur_2)++;
            p->Joueur2=realloc(p->Joueur2,sizeof(Groupe)*p->nb_grp_joueur_2);
            p->Joueur2[p->nb_grp_joueur_2-1]=new;
        }
    }


    return p;
}




void fusionner_groupe()





void freed_Plateau(Plateau p){
    for (unsigned int i = 0; i < p->dim; i++) {
        for (unsigned int j = 0; j < p->dim; j++) {
            free(p->cellule[i][j]);
        }
    }
    for (unsigned int i = 0; i < p->dim; i++) {
        free(p->cellule[i]);
    }
    free(p->cellule);
    for (unsigned int i = 0; i < p->nb_grp_joueur_1; i++) {
        free(p->Joueur1[i]);
    }
    for (unsigned int i = 0; i < p->nb_grp_joueur_2; i++) {
        free(p->Joueur2[i]);
    }
    free(p);
}




//////////////////////////////////////////////////////DEV
void afficher_plateau(Plateau p){
    assert(p);
    printf("================================================\n" );
    for (int i = 0; i < p->dim; i++) {
        for (size_t h = 0; h < i; h++) {
            printf("  " );
        }
        for (int j = 0; j < p->dim; j++) {
            if(p->cellule[i][j]->pion==JOUEUR_1) printf("\\ 1 " );
            else if (p->cellule[i][j]->pion==JOUEUR_2) printf("\\ 2 " );
            else printf("\\ . " );
        }
        printf("\\\n" );
    }
    printf("================================================\n" );
}
