/*!
   \file main.c
   \brief
   \author Sylvain DEKER
   \date 17/05/2017
*/
#define _POSIX_C_SOURCE 1

#include <stdio.h>
#include <stdlib.h>

#include "Structure/Coordonnee/Coordonnee.h"
#include "Structure/Liste/Liste.h"
#include "Structure/Plateau/Plateau.h"
#include "Structure/Sauvegarde/Sauvegarde.h"
#include "Structure/Undo/Undo.h"
#include "Interface_c_java/Interface.h"

#define TAILLE_REQ 255

int main(int argc, char const *argv[]) {


    bool quiter=false;
    char *requete=malloc(sizeof(char)*TAILLE_REQ);
    char*fichier=malloc(sizeof(char)*TAILLE_REQ);
    char*desc=malloc(sizeof(char)*TAILLE_REQ);
    Joueur j1,j2;
    Plateau plateau=NULL;
    int j,x,y;

    int dim;


    while (!quiter) {
        if(lecture_requete(requete)!=0)fprintf(stderr, "Errereur de lecture de la Requete\n" );
        else {

            // printf("%s\n",requete );
            switch (requete[0]) {
                case 'n':
                    j1=contructeur_Joueur();
                    j2=contructeur_Joueur();

                    sscanf(requete,"n(%u)",&dim);
                    plateau=constructeur_plateau(dim,j1,j2);
                    printf("Création d'un plateau de taille %d\n",dim );
                    break;
                case 'g':
                    printf("Envoie de la grille -> Recuperer donnée dans la pipeline c_vers_java \n");
                    envoyer_grille(plateau);
                    break;
                case 'u':
                    printf("Undo\n" );
                    undo(&plateau,1);
                    break;
                case 's':
                    /*Atetion Respecter les espaces*/
                    sscanf(requete,"s( %s , %s )",fichier,desc);
                    printf("Sauvegarde dans %s \n",fichier );
                    sauvegarder_partie(plateau,fichier,desc);
                    break;
                case 'p':

                    sscanf(requete,"p(%d,%d,%d)",&j,&x,&y);
                    if(j==1)poser_un_pion(plateau,Joueur1(plateau),Coord(x,y));
                    if(j==2)poser_un_pion(plateau,Joueur2(plateau),Coord(x,y));
                    printf("Pose du pion %d, sur (%d,%d)\n",j,x,y );
                    break;
                case 't':
                    printf("Fin de la partie\n" );
                    if(plateau!=NULL){
                        freed_all(plateau);
                        plateau=NULL;
                    }
                    break;
                case 'q':
                    quiter=true;
                    break;
                case 'w':
                    printf("Demande si il existe un Gagnant -> Recuperer donnée dans la pipeline c_vers_java \n" );
                    envoyer_existe_gagnant(plateau);


            }
        }

    }


    free(requete);
    free(fichier);
    free(desc);



    return 0;
}
