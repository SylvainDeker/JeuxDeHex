/*!
   \file Plateau.c
   \brief Plateau.c
   \author Sylvain DEKER
   \date 1/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Plateau.h"


struct _plateau{

    unsigned int dimension;
    GRILLE grille;

};

Plateau construction_Plateau(unsigned int dimension){
    assert(dimension>0);
    Plateau plateau=(Plateau)malloc(sizeof(struct _plateau));
    plateau->dimension=dimension;
    plateau->grille=(GRILLE)malloc(sizeof(char*)*dimension);
    for (int i = 0; i < dimension; i++) {
        plateau->grille[i]=(char*)malloc(sizeof(char)*dimension);
    }
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            plateau->grille[i][j]=VIDE;
        }
    }
    return plateau;
}

void placer_Pion(Plateau plateau,Joueur joueur,Coordonnee c){
    assert(c.x>=0 && c.x< plateau->dimension);
    assert(c.y>=0 && c.y< plateau->dimension);
    assert(plateau->grille[c.x][c.y]==VIDE);

    plateau->grille[c.x][c.y]=joueur;

}

Joueur connaitre_Pion(Plateau plateau,Coordonnee c){
    assert(c.x>=0 && c.x< plateau->dimension);
    assert(c.y>=0 && c.y< plateau->dimension);
    return plateau->grille[c.x][c.y];
}

Coordonnee obtenir_voisin(Coordonnee c,int link){
    assert(link>=0&&link<7);
    Coordonnee voisin;
    switch (link) {
        case 0:
            voisin.x=c.x-1;
            voisin.y=c.y;
            break;
        case 1:
            voisin.x=c.x-1;
            voisin.y=c.y+1;
            break;
        case 2:
            voisin.x=c.x;
            voisin.y=c.y+1;
            break;
        case 3:
            voisin.x=c.x+1;
            voisin.y=c.y;
            break;
        case 4:
            voisin.x=c.x+1;
            voisin.y=c.y-1;
            break;
        case 5:
            voisin.x=c.x;
            voisin.y=c.y-1;
            break;
    }
    return voisin;
}

void freed_Plateau(Plateau plateau){
    assert(plateau);
    for (int i = 0; i < plateau->dimension; i++) {
        free(plateau->grille[i]);
    }
    free(plateau->grille);
    free(plateau);
}

//////////////////////////////////////////////////////DEV
void afficher_plateau(Plateau plateau){
    assert(plateau);
    printf("=============================================\n" );
    for (int i = 0; i < plateau->dimension; i++) {
        for (size_t h = 0; h < i; h++) {
            printf("  " );
        }
        for (int j = 0; j < plateau->dimension; j++) {
            if(plateau->grille[i][j]==JOUEUR_1) printf("\\ 1 " );
            else if (plateau->grille[i][j]==JOUEUR_2) printf("\\ 2 " );
            else printf("\\   " );
        }
        printf("\\\n" );
    }
    printf("=============================================\n" );
}
