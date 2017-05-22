
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

    /*!
       \brief Constructeur du solveur
       \param Plateau plateau
       \param Arbre_solveur as
       \param int joueur_gagnant est les joueur joué par l'ordinateur
       \return Solveur
    */

    Solveur constructeur_solveur(Plateau plateau_reference,Arbre_solveur as,int joueur_gagnant);

    /*!
       \brief Recupere le prochain coups donné par l'advessire
       \param Solveur sv
       \param Coordonnee c
    */
    void prochain_coup_adversaire(Solveur sv,Coordonnee c);

    /*!
       \brief Fonction permetant d'obtenir les Coordonnee du prochaine coups (machine)
       \param Solveur
       \return Coordonnee
    */

    Coordonnee obtenir_coordonnee_prochain_coup_gagnant(Solveur sv);
    /*!
       \brief Libérateur du Solveur
       \param Solveurthe function"
    */
    void freed_solveur(Solveur slv);
    /*!
       \brief Fonction pour faire jouer la machinne
       \param Solveur sv
       \pre "Pre-conditions"
       \post "Post-conditions"
       \return "Return of the function"
    */
    void jouer_prochain_coup(Solveur sv);

#endif
