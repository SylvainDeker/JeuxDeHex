/*!
   \file Plateau.h
   \brief Plateau.h
   \author Sylvain DEKER
   \date 1/05/2017
*/
#define _POSIX_C_SOURCE 1

#ifndef _PLATEAU_H_
#define _PLATEAU_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <assert.h>
    #include "Coordonnee/Coordonnee.h"
    #define VIDE 'v'
    #define JOUEUR_1 '1'
    #define JOUEUR_2 '2'
    #define Pion char
    typedef struct _plateau*Plateau;
    Plateau constructeur_plateau(unsigned int dimention);
    void freed_Plateau(Plateau p);











#endif
