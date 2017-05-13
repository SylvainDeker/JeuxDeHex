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
    /*!
       \brief Sauve une partie en cours
       \param Plateau
       \param Nome et chemin du fichier de sauvegarde
       \post Fichier ecraseé si existant
       \return 1 si la sauvegarde s'est bien passé 0 sinon
    */
    bool sauvegarder_partie(Plateau p,const char*nom_fichier,const char*description);
    /*!
       \brief Restaure une partie en cours
       \param Nome et chemin du fichier de sauvegarde
       \param Plateau
       \pre fichier formaté avec la fonction sauvegarder_partie()
       \return 1 si la restauration s'est bien passé, 0 sinon
    */
    bool restaurer_partie(const char * nom_fichier,Plateau *out);



    

#endif
