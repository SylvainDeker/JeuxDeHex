/*!
   \file Undo.c
   \brief Undo.c
   \author Sylvain DEKER
   \date 13/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Undo.h"
#define FICHIER_CACHE "temp.txt"

bool undo(Plateau *p, int nb_undo){
    sauvegarder_partie(*p,FICHIER_CACHE,"Undo");







    return 1;
}

bool suppression_desd_dernieres_lignes(const char * nom_fichier){
    FILE *fichier_sauvegarde=fopen(nom_fichier,"r+");
    if(fichier_sauvegarde){
        fseek(fichier_sauvegarde,-26,SEEK_END);
        
        fclose(fichier_sauvegarde);
    }




    return 1;
}
