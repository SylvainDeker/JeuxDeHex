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

    /* /!\    Si le groupe associé a la case == NULL ca veut dire que la case est vide  /!\ */

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
       \brief Freed tout les malloc du plateau et joueur
       \param Plateau
    */
    void freed_all(Plateau p);


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
       \brief Determine si il existe un gagnant
       \param Plateau
       \return NULL si pas de gagnant, pointeur sur Joueur designat le gagnant sinon
    */
    Joueur Existe_Gangnant(Plateau p);


    /*!
       \brief Determine si une case est vide on non
       \param Plateau
       \param Coordonnee de la case
       \pre "Pre-conditions"
       \post "Post-conditions"
       \return "Return of the function"
    */
    bool Case_Vide(Plateau p,Coordonnee c);

    /*!
       \brief Determine les Coordonnee d'une case à partir de son pointeur
       \param Case
       \return Coordonnee
    */
    Coordonnee Coordonne_de_la_Case(Case ca);

    /*!
       \brief Determine le groupe auquel appartient la case
       \param Case
       \return Groupe si la case n'est pas vide sinon NULL
    */
    Groupe Groupe_de_la_Case(Case ca);
    /*!
       \brief Renvoi la case à partir de sa Coordonnee
       \param Plateau
       \return Case
    */
    Case Case_de_la_Coordonnee(Plateau p,Coordonnee c);
    /*!
       \brief Revoi un poiteur vers la liste des groupe de cases associé à un joueur
       \param Joueur
       \return Liste
       \WARN ne pas oublier de caster !
       \note: Utiliser l'itarteur pour ne pas depiler
    */

    Liste Liste_Groupe_du_Joueur(Joueur j);
    /*!
       \brief Revoi un poiteur vers la liste des cases associé à un groupe
       \param Joueur
       \return Liste
       \WARN ne pas oublier de caster !
       \note: Utiliser l'itarteur pour ne pas depiler
    */
    Liste Liste_Case_du_Groupe(Groupe g);

    /*!
       \brief Determine le joueur associé à un groupe
       \param Groupe
       \return "Return of the function"
    */
    Joueur Joueur_du_groupe(Groupe g);

    /*!
       \brief Determine si une case du groupe est connecter au mur 1
       \param Groupe
       \pre Groupe != NULL
       \return bool 1 si connecter 0 sinon
    */
    bool Groupe_co_au_mur1(Groupe g);


    /*!
       \brief Determine si une case du groupe est connecter au mur 1
       \param Groupe
       \pre Groupe != NULL
       \return bool 1 si connecter 0 sinon
    */
    bool Groupe_co_au_mur2(Groupe g);
    /*!
       \brief Determine N la dimention N * N du Plateau
       \param Plateau
       \return unsigned int !
    */
    unsigned int Dimention_plateau(Plateau p);

    /*!
       \brief Renvoi Joueur1
       \param Plateau
       \return Joueur1
    */
    Joueur Joueur1(Plateau p);


    /*!
       \brief Renvoi Joueur1
       \param Plateau
       \return Joueur1
    */
    Joueur Joueur2(Plateau p);

    /*!
       \brief Retourne Liste de cases ou un pion à été placé par un joueurs depuis le debut de la partie
       \param Joueur
       \return Liste de case
    */
    Liste Historique_Joueur(Joueur j);

    /*!
       \brief Parcours les emplacements et retourne les Coordonnee du primier vide
       \param Plateau
       \return Coordonnee
    */
    Coordonnee Emplacement_libre(Plateau p);

#endif
