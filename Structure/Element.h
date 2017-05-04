/*!
   \file Element.h
   \brief Structure de donnée des élements de base du jeux, plateau, pions etc..
   \author Sylvain DEKER
   \date 30/04/2017
*/
#define _POSIX_C_SOURCE 1

#ifndef _ELEMENT_H_
#define _ELEMENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Coordonnee.h"

typedef struct _jeux *Jeux;
typedef struct _coordonnee * Coordonnee;
#define CASE char
#define VIDE 0
#define JOUEUR1 1
#define JOUEUR2 2


Jeux Constructeur_jeux(unsigned int taille_plateau);
void freed_jeux(Jeux j,unsigned int taille_plateau);

bool placer_pion_jeux(Jeux j,char joueur,unsigned int position_x,unsigned int position_y);
CASE status_case_jeux(Jeux j,unsigned int position_x,unsigned int position_y);

void afficher_plateaux(Jeux j);


#endif
