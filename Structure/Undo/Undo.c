/*!
   \file Undo.c
   \brief Undo.c
   \author Sylvain DEKER
   \date 13/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Undo.h"


unsigned int max(unsigned int a,unsigned b);

void undo(Plateau *p,unsigned int nb_undo){
    unsigned int taille_listes=liste_taille(Historique_Joueur(Joueur1(*p)))+liste_taille(Historique_Joueur(Joueur2(*p)));
    assert( taille_listes >= nb_undo );
    ListeItr itr_historique_joueur1,itr_historique_joueur2;

    itr_historique_joueur1=constructeur_liste_iterateur(Historique_Joueur(Joueur1(*p)),FIFO);
    itr_historique_joueur2=constructeur_liste_iterateur(Historique_Joueur(Joueur2(*p)),FIFO);

    start_liste_iterateur(itr_historique_joueur1);
    start_liste_iterateur(itr_historique_joueur2);
    Case cas;
    Coordonnee cd;
    //Création d'une nouvelle structure de jeux
    Joueur j1=contructeur_Joueur();
    Joueur j2=contructeur_Joueur();
    Plateau p_new=constructeur_plateau(Dimention_plateau(*p),j1,j2);

    unsigned int i=0;
    //On remet l'essmble des pion jusqu'a nb_undo-avant dernier
    while(i<taille_listes-nb_undo){
        if(!fin_liste_iterateur(itr_historique_joueur1)){
            cas=(Case)liste_iterateur_courant(itr_historique_joueur1);
            cd=Coordonne_de_la_Case(cas);
            poser_un_pion(p_new,j1,cd);
            suivant_liste_iterateur(itr_historique_joueur1);
            i++;
        }
        if(!fin_liste_iterateur(itr_historique_joueur2)&& i<taille_listes-nb_undo){
            cas=(Case)liste_iterateur_courant(itr_historique_joueur2);
            cd=Coordonne_de_la_Case(cas);
            poser_un_pion(p_new,j2,cd);
            suivant_liste_iterateur(itr_historique_joueur2);
            i++;
        }
    }
    freed_liste_iterateur(itr_historique_joueur1);
    freed_liste_iterateur(itr_historique_joueur2);
    //Libération de l'acienne version
    freed_all(*p);
    *p=p_new;
}
