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
    #include "Coordonnee/Coordonnee.h"
    #define GRILLE char**
    typedef struct _plateau*Plateau;
    #define VIDE 0
    #define JOUEUR_1 1
    #define JOUEUR_2 2
    #define Joueur char
    /*!
       \brief Constructeur du plateau du jeux
       \param dimention*dimention = nombre de case de la grille
       \post Grille vide inittialisé à vide
       \return Pointeur vers une structure "Plateau"
    */
    Plateau construction_Plateau(unsigned int dimension);

    /*!
       \brief Permet de placer un pion à des Coordonnee x,y
       \param Plateau
       \param Joueur est definit dans Plateau.h (#define)
       \return bool=false si impossible de positionner le pion (effet de bords, place deja prise)
    */
    bool placer_Pion(Plateau plateau,Joueur joueur,Coordonnee c);

    /*!
       \brief Libération de la mémoire
       \param Plateau
       \pre plateau doit etre initialisé par construction_Plateau()
    */
    void freed_Plateau(Plateau plateau);

    /*!
       \brief Affichage du plateau dans la console pour test
       \param Plateau
       \pre plateau doit etre initialisé par construction_Plateau()
    */
    void afficher_plateau(Plateau plateau);

    /*!
       \brief Connaitre l'existance d'un emplacement par ces cooredonnées
       \param Plateau
       \param Coordonnee
       \pre plateau doit etre initialisé par construction_Plateau()
       \return JOUEUR_1 ou JOUEUR_2 ou VIDE
    */
    Joueur connaitre_Pion(Plateau plateau,Coordonnee c);

    /*!
       \brief Permet d'obtenir les coordonnée d'un voisin en fonction de link:
               i=0 en haut
               i=1 en haut à droite
               i=2 en à droite
               i=3 en bas à droite
               i=4 en bas
               i=5 en bas à gauche
       \param Coordonnee
       \param int 0,1,2,3,4 ou 5 uniquement
       \return Coordonnee voisin
       \Warn Gerer les effets de bords, d'emplecment deja pris apres coups
    */
    Coordonnee obtenir_voisin(Coordonnee c,int link);

#endif
