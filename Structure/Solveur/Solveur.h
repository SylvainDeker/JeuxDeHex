/*!
   \file Solveur.h
   \brief Solveur.h
   \author Sylvain DEKER
   \date 11/05/2017
*/
#define _POSIX_C_SOURCE 1

#ifndef _SOLVEUR_H_
#define _SOLVEUR_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <assert.h>
    #include "../Plateau/Plateau.h"
    #include "../Coordonnee/Coordonnee.h"
    #include "../Liste/Liste.h"

typedef struct _arbre_possibilites*Arbre_solveur;

Arbre_solveur constructeur_arbre_solveur(Plateau p);
Plateau copie_de_plateau(Plateau p);

void affichage_as(Arbre_solveur as);


#endif
