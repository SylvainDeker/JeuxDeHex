/*!
   \file Element.c
   \brief Structure de donnée des élements de base du jeux, plateau, pions etc..
   \author Sylvain DEKER
   \date 30/04/2017
*/
#define _POSIX_C_SOURCE 1
#include "Element.h"




struct _jeux{
    /*On cocidère ici le plateau comme un tableau a 2 dimentions*/
    unsigned int taille_plateau;
    char **plateau;
};






Jeux Constructeur_jeux(unsigned int taille_plateau){

    Jeux j=(Jeux)malloc(sizeof(struct _jeux));
    j->plateau=(CASE**)malloc(sizeof(CASE*)*taille_plateau);

    for (int itr = 0; itr < taille_plateau; itr++) {
        j->plateau[itr]=(CASE*)malloc(sizeof(CASE)*taille_plateau);
    }
    for ( int i = 0; i < taille_plateau; i++) {
        for ( int h = 0; h < taille_plateau; h++) {

            j->plateau[i][h]=VIDE;
        }
    }
    j->taille_plateau=taille_plateau;
    return j;
}

bool placer_pion_jeux(Jeux j,char joueur,unsigned int position_x,unsigned int position_y){
    bool placement_valide;

    if(position_x>=j->taille_plateau || position_y>=j->taille_plateau ){
        fprintf(stderr, "Erreur dépassement : placer_pion_jeux : position_x = %u position_y = %u\n",position_x,position_y );
        exit(1);
    }

    if(j->plateau[position_x][position_y]!=VIDE){
        placement_valide=false;
    }
    else{
        placement_valide=true;
        j->plateau[position_x][position_y]=joueur;
    }
    return placement_valide;
}

CASE status_case_jeux(Jeux j,unsigned int position_x,unsigned int position_y){
    if(position_x>=j->taille_plateau || position_y>=j->taille_plateau ){
        fprintf(stderr, "Erreur dépassement : status_case_jeux : position_x = %u position_y = %u\n",position_x,position_y );
        exit(1);
    }
    return j->plateau[position_x][position_y];
}



void afficher_plateaux(Jeux j){

    for ( int i = 0; i < j->taille_plateau; i++) {
        for (int y = 0; y < i; y++) {
            printf("  ");
        }
        printf("\\" );
        for ( int h = 0; h < j->taille_plateau; h++) {

            if(j->plateau[i][h]==VIDE)   printf("| . ");
            else if(j->plateau[i][h]==JOUEUR1)      printf("| 1 ");
            else printf("| 2 " );
        }
        printf("|\\ \n" );
    }

}




void freed_jeux(Jeux j,unsigned int taille_plateau){
    for (int itr = 0; itr < taille_plateau; itr++) {
        free(j->plateau[itr]);
    }
    free(j->plateau);
    free(j);
}
