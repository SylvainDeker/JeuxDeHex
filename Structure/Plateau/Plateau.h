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
    #include "../Coordonnee/Coordonnee.h"
    #include "../Liste/Liste.h"

    typedef struct _joueur * Joueur;
    typedef struct _case * Case;
    typedef struct _groupe * Groupe;
    typedef struct _plateau * Plateau;

    /*!
       \brief Constructeur Joueur
       \return Joueur
    */
    Joueur contructeur_Joueur();
    /*!
       \brief Constructeur du Plateau (construit aussi toute les autre structure nécéssaire)
       \return Plateau
    */
    Plateau constructeur_plateau(unsigned int taille_grille, Joueur j1,Joueur j2);

    /*!
       \brief Pose un pion dans une case
       \param Plateau
       \param Joueur
       \param Coordonnee ou poser le pion
       \pre La case doit etre vide
       \post La case est pleinne
       \return poiteur vers la case
    */
    Case poser_un_pion(Plateau p, Joueur j,Coordonnee c);

    /*!
       \brief Determine si une case est vide on non
       \param Plateau
       \param Coordonnee de la case
       \pre "Pre-conditions"
       \post "Post-conditions"
       \return "Return of the function"
    */
    bool check_case_vide(Plateau p,Coordonnee c);

    /*!
       \brief Freed tout les malloc du plateau et joueur
       \param Plateau
    */
    void freed_all(Plateau p);
    /*!
       \brief Determine si il existe un gagnant
       \param Plateau
       \return NULL si pas de gagnant, pointeur sur Joueur designat le gagnant sinon
    */
    Joueur Existe_Gangnant(Plateau p);



    //Tests !
    /*
                    Mur 1
                    Joueur 0
        \ 1 \ 1 \ o \ o \ o \ o \ o \ o \
          \ o \ 1 \ o \ o \ o \ o \ 1 \ 1 \
            \ 1 \ o \ o \ 1 \ 1 \ 1 \ 1 \ o \
              \ 1 \ o \ . \ 1 \ 1 \ o \ o \ o \     Mur2
    Mur1        \ 1 \ . \ 1 \ o \ . \ o \ o \ o \   Joueur 1
    Joueur 1      \ 1 \ 1 \ 1 \ o \ o \ . \ . \ o \
                    \ o \ 1 \ 1 \ . \ o \ 1 \ 1 \ 1 \
                      \ 1 \ o \ o \ 1 \ o \ 1 \ . \ 1 \
                                    Mur 2
                                    joueur 0
    */
    void afficher_plateau(Plateau p);
    void bilan(Plateau p);

#endif
