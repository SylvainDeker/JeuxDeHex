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

    Joueur contructeur_Joueur();
    Plateau constructeur_plateau(unsigned int taille_grille, Joueur j1,Joueur j2);
    void freed_Joueur(Joueur j);
    void freed_plateau(Plateau p);
    Case poser_un_pion(Plateau p, Joueur j,Coordonnee c);
    void voisin_etant_du_joueur(Plateau p,Joueur j,Coordonnee c, Liste l );
    void fusionner_groupe(Groupe g1, Groupe g2);
    bool check_case_vide(Plateau p,Coordonnee c);

    void freed_all(Plateau p);
    Groupe Groupe_de_la_Case(Case ca);
    Coordonnee Coordonnee_Case(Case ca);
    void afficher_plateau(Plateau p);
    void bilan(Plateau p);

#endif
