
/*!
   \file Arbre.h
   \brief Arbre.h
   \author Sylvain DEKER
   \date 11/05/2017
*/
#define _POSIX_C_SOURCE 1

#ifndef _ARBRE_H_
#define _ARBRE_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <assert.h>
    #include "../Plateau/Plateau.h"
    #include "../Coordonnee/Coordonnee.h"
    #include "../Liste/Liste.h"

    typedef struct _arbre_possibilites*Arbre_solveur;
    typedef struct _noeud*Noeud;


    /*!
       \brief Application Recursif de l'algorithme minmax
       \param Arbre_solveur
       \param Noeud nd
       \param int *j1 poids minamx du joueur 1 sur un noeud
       \param int *j2 poids minamx du joueur 1 sur un noeud
       \info Le poids minmax des jours au niveau de ma feuille est calculé de facon suivante:
            Si la feuille est gagnante par le joueur 1 alors le poids du Joueur1 prend 10 plus le nombre de case vide
            Le Joueur2 à un poid de 0. La constante 10 est faite pour augement la Difference en en poids des deux joueurs
    */
    void application_minmax(Arbre_solveur as);



    /*!
       \brief constructeur de l'arbre avec le Plateau p
       \param Plateau p
       \return Arbre_solveur
    */
    Arbre_solveur constructeur_arbre_solveur(Plateau p);

    /*!
       \brief Cette fonction sert à effectuer un copier du plateua pour pouvoir le duplique dans un arbre
       \param Plateau p
       \return Plateau
    */
    Plateau copie_de_plateau(Plateau p);

    /*!
       \brief Libere l'arbre
       \param Arbre Solveur

    */
    void freed_arbre_solveur(Arbre_solveur as);

    /*!
       \brief Determine un nombre representant les chance de gagné pour un Joueur
       \param Arbre_solveur
       \return int
    */
    int potentiel_gagnant_joueur2(Arbre_solveur);

    /*!
       \brief Determine un nombre representant les chance de gagné pour un Joueur
       \param Arbre_solveur
       \return int
    */
    int potentiel_gagnant_joueur1(Arbre_solveur);

    /*!
       \brief La sentinnelle de l'arbre est sa racine
       \param Arbre_solveur as
       \return Noeuds
    */
    Noeud sentinelle_arbre_solveur(Arbre_solveur as);

    /*!
       \brief Retourne le tableau de fils represeant toutes les possibilité (toutes le branches) du Noeud
       \param Noeuds
       \return "Return of the function"
    */
    Noeud *tableau_fils_noeud(Noeud nd);

    /*!
       \brief Determine le nombre de fils d'un Noeud
       \param Noud nd
       \return unsigned int
    */
    unsigned int nb_fils_noeud(Noeud nd);
    /*!
       \brief Connaitre le poids du Joueur à un nnoeud donnée
       \param Noeud
       \return int le poids
    */
    int poids_j1_noeud(Noeud nd);
    /*!
       \brief Connaitre le poids du Joueur 2 à un noeud donnée
       \param Noeud
       \return int le poids
    */
    int poids_j2_noeud(Noeud nd);
    /*!
       \brief Revoie les Coordonnee de la case sur lequelle il y a eu des changements
       \param Noeud nd
       \return Coordonnee
    */
    Coordonnee coordonnee_noeud(Noeud nd);
    /*!
       \brief Determine si un noeud est une feuille
       \param Noeud
       \return
    */
    bool est_une_feuille_noeud(Noeud nd);
    // void affichage_as(Arbre_solveur as);
        // void affichage_minmax(Arbre_solveur);
#endif
