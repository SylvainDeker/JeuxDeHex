/*!
   \file Sauvegarde.h
   \brief Sauvegarde.h
   \author Sylvain DEKER
   \date 11/05/2017
*/
#define _POSIX_C_SOURCE 1

#ifndef _UNDO_H_
#define _UNDO_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <assert.h>
    #include "../Sauvegarde/Sauvegarde.h"
    #include "../Coordonnee/Coordonnee.h"
    #include "../Liste/Liste.h"
    #include "../Plateau/Plateau.h"

    bool undo(Plateau *p, int nb_undo);
#endif
