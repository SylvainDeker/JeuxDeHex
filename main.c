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
#include "Structure/Arbre/Arbre.h"

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

            switch (requete[0]) {
                case 'n':
                    j1=contructeur_Joueur();
                    j2=contructeur_Joueur();

                    sscanf(requete,"n(%u)",&dim);
                    plateau=constructeur_plateau(dim,j1,j2);
                    printf("Création d'un plateau de taille %d\n",dim );
                    break;
                case 'g':
                    assert(plateau);
                    printf("Envoie de la grille -> Recuperer donnée dans la pipeline c_vers_java \n");
                    envoyer_grille(plateau);
                    break;
                case 'u':
                    assert(plateau);
                    printf("Undo\n" );
                    undo(&plateau,1);
                    break;
                case 's':
                    assert(plateau);
                    /*Atetion Respecter les espaces*/
                    sscanf(requete,"s( %s , %s )",fichier,desc);
                    printf("Sauvegarde dans %s \n",fichier );
                    sauvegarder_partie(plateau,fichier,desc);
                    break;
                case 'p':
                    assert(plateau);
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
                        j1=NULL;
                        j2=NULL;
                    }
                    break;
                case 'q':
                    printf("Quiter \n" );
                    quiter=true;
                    break;

                case 'r':

                    printf("Restauration\n" );
                    sscanf(requete,"r( %s )",fichier);
                    j1=contructeur_Joueur();
                    j2=contructeur_Joueur();

                    int res=restaurer_partie(fichier,&plateau,&j1,&j2);
                    if(res){
                        envoyer_chaine("1\n");
                    }
                    else{
                        envoyer_chaine("0\n");
                        j1=NULL;
                        j2=NULL;
                        plateau=NULL;
                    }

                    break;

                case 'w':
                    assert(plateau);
                    printf("Demande si il existe un Gagnant -> Recuperer donnée dans la pipeline c_vers_java \n" );
                    envoyer_existe_gagnant(plateau);
                    break;
                case 'e':
                    assert(plateau);
                    sscanf(requete,"e(%d,%d)",&x,&y);
                    printf("Demande si il existe un pion sur %d,%d -> Recuperer donnée dans la pipeline c_vers_java \n",x,y );
                    envoyer_joueur_case(plateau,Coord(x,y));
                    break;
                case 'b':
                    assert(plateau);
                    printf("Demande du nombre case libre restante \n" );
                    envoyer_nombre_place_libre(plateau);
                    break;
                // case 'f':
                //     assert(plateau);
                //     printf("Demande de donnée \"potentiel gagnant\"\n");
                //     envoyer_potentiel_gagnant(plateau);
                //     printf("Terminé.\n" );
                //     break;
                default:
                    fprintf(stderr, "Entree invalide\n");
            }
        }

    }
    if(plateau!=NULL){
        freed_all(plateau);
    }

    free(requete);
    free(fichier);
    free(desc);



    return 0;
}
