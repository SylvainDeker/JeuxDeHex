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

    /*!
       \brief Permet de retirer les nb_undo derniers pions posés sur le jeux
       \param * Plateau
       \pre assert(taille_listes-nb_undo >= 0);
       \post - nb_undo pion sur le jeux
    */
    void undo(Plateau *p,unsigned int nb_undo);



    
#endif
