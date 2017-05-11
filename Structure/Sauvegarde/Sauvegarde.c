/*!
   \file Sauvegarde.c
   \brief Sauvegarde.c
   \author Sylvain DEKER
   \date 11/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Sauvegarde.h"



bool sauvegarder_partie(Plateau p,const char*nom_fichier,const char*description){
    unsigned int dim=Dimention_plateau(p);
    FILE*fichier_sauvegarde=fopen(nom_fichier,"w");
    if(fichier_sauvegarde){

        fprintf(fichier_sauvegarde, "\\hex\n\\dim %u\n\\board %s\n",dim,description);


        for (unsigned int i = 0; i < dim-1; i++){
            fprintf(fichier_sauvegarde, "W ");
        }
        fprintf(fichier_sauvegarde, "W/B\n");
        for (unsigned int i = 0; i < dim; i++){
            for (unsigned int j = 0; j < i; j++){
                fprintf(fichier_sauvegarde,"  ");
            }
            fprintf(fichier_sauvegarde, "B ");
            for ( unsigned int j = 0; j < dim; j++) {
                if(!Case_Vide(p,Coord(i,j))){
                    if(Joueur_du_groupe( Groupe_de_la_Case( Case_de_la_Coordonnee(p,Coord(i,j)) ) )==Joueur1(p))
                        fprintf(fichier_sauvegarde,"* " );
                    else
                        fprintf(fichier_sauvegarde,"o " );
                }
                else fprintf(fichier_sauvegarde,". " );
            }
            fprintf(fichier_sauvegarde, "B\n");
        }
        for (unsigned int j = 0; j < dim; j++){
            fprintf(fichier_sauvegarde,"  ");
        }
        fprintf(fichier_sauvegarde, "B/W ");
        for (unsigned int i = 0; i < dim-1; i++){
            fprintf(fichier_sauvegarde, "W ");
        }
        fprintf(fichier_sauvegarde, "\n\\game\n");
        //TODO historique
        fprintf(fichier_sauvegarde, "\\endgame\n");
        fprintf(fichier_sauvegarde, "\\endhex\n");

        fclose(fichier_sauvegarde);
    }

    return (bool)fichier_sauvegarde;
}
