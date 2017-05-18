
/*!
   \file Arbre.h
   \brief Arbre.h
   \author Sylvain DEKER
   \date 11/05/2017
*/
#define _POSIX_C_SOURCE 1

#ifndef _ARBRE_H_
#define _ARBRE_H_
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
    void freed_arbre_solveur(Arbre_solveur as);
    void affichage_as(Arbre_solveur as);
    int potentiel_gagnant_joueur2(Arbre_solveur);
    int potentiel_gagnant_joueur1(Arbre_solveur);
    void application_minmax(Arbre_solveur as);
    void affichage_minmax(Arbre_solveur);

#endif
