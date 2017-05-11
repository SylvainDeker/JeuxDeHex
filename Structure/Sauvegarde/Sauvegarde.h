/*!
   \file Sauvegarde.h
   \brief Sauvegarde.h
   \author Sylvain DEKER
   \date 11/05/2017
*/
#define _POSIX_C_SOURCE 1

#ifndef _SAUVEGARDE_H_
#define _SAUVEGARDE_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <assert.h>
    #include "../Coordonnee/Coordonnee.h"
    #include "../Liste/Liste.h"
    #include "../Plateau/Plateau.h"
    bool sauvegarder_partie(Plateau p,const char*nom_fichier,const char*description);

#endif
