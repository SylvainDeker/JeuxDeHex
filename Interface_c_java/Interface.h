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

    /*!
       \brief Fonction permetant de lire les instruction du programme java
       \param [out] ordre
       \return 0 si lecture reussi, -1 sinon
    */
    int lecture_requete(char * ordre);

    /*!
       \brief Permet d'envoyer une information sous forme d'une chaine de caractère formaté au au programme java
       \param Chaine
       \return 0 si envoi reussi -1 sinon
    */
    int envoyer_grille(Plateau p);

    /*!
       \brief Permet d'envoyer le plateau sous forme d'une chaine de caractère formaté au au programme java
       \param Chaine
       \return 0 si envoi reussi -1 sinon
    */
    int envoyer_existe_gagnant(Plateau p);

    /*!
       \brief Permet d'envoyer un potentiel gagnant sous forme d'une chaine de caractère formaté au au programme java
       \param Chaine
       \return 0 si envoi reussi -1 sinon
    */
    int envoyer_joueur_case(Plateau p,Coordonnee c);

    /*!
       \brief Permet au programme java savoir si un pion est présent sur une case et si oui lequel
       \param Plateau
       \param Coordonnee
       \return 0 si envoi reussi -1 sinon
    */
    int envoyer_nombre_place_libre(Plateau p);

    /*!
       \brief Permet d'envoyer au programme java le nombre la place libre restantes
       \param Plateau
       \return 0 si envoi reussi -1 sinon
    */
    int envoyer_potentiel_gagnant(Plateau p);

    /*!
       \brief Permet d'envoyer au programme java le ganant si il existe
       \param Plateau
       \return 0 si envoi reussi -1 sinon
    */

    int envoyer_chaine(char*word);


    /*!
       \brief Permet d'envoyer au programme des Coordonnee formaté
       \param Coordonnee c
       \return 0 si bien envoyé , -1 sinon
    */
    int envoyer_coordonnee(Coordonnee c);

#endif
