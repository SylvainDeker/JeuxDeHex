/*!
   \file Undo.c
   \brief Reconstruction d'un plateau et recopie des valeurs jusqu'a l'avant derniere. Ce chois se justifi par le fait que la structure Plateau contient les groupe qui sont construit au fur et à mesure et fusionné si besoin
        Un retrait de pion "chirugical" dans ce cas demanderai un scan complet du plateau à plusieur reprise, Il est donc plus interessant d'en reconstruire un autre
   \author Sylvain DEKER
   \date 13/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Undo.h"


unsigned int max(unsigned int a,unsigned b);

/*!
   \brief Permet de revenir en arriere
   \param Plateau *p
   \pre au moin un pion posé
   \pose reprise d'un etat précedant
*/

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
