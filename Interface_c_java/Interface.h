/*!
   \file Interface.h
   \brief Interface.h
   \author Sylvain DEKER
   \date 17/05/2017
*/
#define _POSIX_C_SOURCE 1

#ifndef _INTERFACE_H_
#define _INTERFACE_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <assert.h>
    #include "../Structure/Sauvegarde/Sauvegarde.h"
    #include "../Structure/Coordonnee/Coordonnee.h"
    #include "../Structure/Liste/Liste.h"
    #include "../Structure/Plateau/Plateau.h"
    #include "../Structure/Arbre/Arbre.h"
    #include "../Structure/Undo/Undo.h"


    int lecture_requete(char * ordre);
    int envoyer_grille(Plateau p);
    int envoyer_existe_gagnant(Plateau p);
    int envoyer_joueur_case(Plateau p,Coordonnee c);
    int envoyer_nombre_place_libre(Plateau p);
    int envoyer_potentiel_gagnant(Plateau p);
    int envoyer_chaine(char*word);
    int envoyer_coordonnee(Coordonnee c);

#endif
