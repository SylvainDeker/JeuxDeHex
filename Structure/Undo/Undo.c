/*!
   \file Undo.c
   \brief Undo.c
   \author Sylvain DEKER
   \date 13/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Undo.h"
#define FICHIER_CACHE "temp.txt"
unsigned int nb_ligne_fichier(FILE *fichier);

bool undo(Plateau *p, int nb_undo){
    sauvegarder_partie(*p,FICHIER_CACHE,"Undo");

    FILE*f=fopen(FICHIER_CACHE,"r");
    if(f){
        printf("TAILLLLLLLLLLLLLLLLLE :%u\n",nb_ligne_fichier(f) );
        fclose(f);
    }







    return 1;
}


unsigned int nb_ligne_fichier(FILE *fichier){
    int c;
    int nb_line = 1;
    while ((c = getc(fichier)) != EOF){
        if (c == '\n')nb_line++;
    }

    return nb_line;
}
