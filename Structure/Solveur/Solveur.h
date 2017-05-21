
/*!
   \file Arbre.h
   \brief Arbre.h
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
    #include "../Arbre/Arbre.h"

    typedef struct _solveur*Solveur;
    Solveur constructeur_solveur(Plateau plateau_reference,Arbre_solveur as,int joueur_gagnant);

    void prochain_coup_adversaire(Solveur sv,Coordonnee c);
    Coordonnee obtenir_coordonnee_prochain_coup_gagnant(Solveur sv);

    void freed_solveur(Solveur slv);
    void jouer_prochain_coup(Solveur sv);

#endif
