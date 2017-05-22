
/*!
   \file Arbre.c
   \brief
   \author Sylvain DEKER
   \date 14/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Arbre.h"

struct _noeud{
    unsigned int nb_fils;
    Plateau plateau;
    struct _noeud ** fils;
    bool est_une_feuille;
    int poids_j1;
    int poids_j2;
    Coordonnee c;
    int j;//1 ou 2
};

struct _arbre_possibilites{
    Noeud sentinelle;
    Plateau p;
    unsigned int nb_possibilite_gagnante_j1;
    unsigned int nb_possibilite_gagnante_j2;
};


// void affichage_plateau(Plateau p);


void feed_arbre_solveur_rec(Plateau p,Arbre_solveur as,Noeud nd,unsigned int possibilites,int joueur);


/*!
   \brief La sentinnelle de l'arbre est sa racine
   \param Arbre_solveur as
   \return Noeuds
*/
Noeud sentinelle_arbre_solveur(Arbre_solveur as){
    return as->sentinelle;
}

/*!
   \brief Retourne le tableau de fils represeant toutes les possibilité (toutes le branches) du Noeud
   \param Noeuds
   \return "Return of the function"
*/

Noeud* tableau_fils_noeud(Noeud nd){
    if(nd->est_une_feuille)
        return NULL;
    else
        return nd->fils;
}
/*!
   \brief Determine le nombre de fils d'un Noeud
   \param Noud nd
   \return unsigned int
*/
unsigned int nb_fils_noeud(Noeud nd){
    return nd->nb_fils;
}

/*!
   \brief Connaitre le poids du Joueur à un nnoeud donnée
   \param Noeud
   \return int le poids
*/
int poids_j1_noeud(Noeud nd){
    return nd->poids_j1;
}

/*!
   \brief Connaitre le poids du Joueur 2 à un noeud donnée
   \param Noeud
   \return int le poids
*/
int poids_j2_noeud(Noeud nd){
    return nd->poids_j2;
}
/*!
   \brief Revoie les Coordonnee de la case sur lequelle il y a eu des changements
   \param Noeud nd
   \return Coordonnee
*/
Coordonnee coordonnee_noeud(Noeud nd){
    return nd->c;
}

/*!
   \brief Determine si un noeud est une feuille
   \param Noeud
   \return
*/
bool est_une_feuille_noeud(Noeud nd){
    return nd->est_une_feuille;
}

/*!
   \brief Constructeur d'un Noeuds
   \param Plateau p
   \param unsigned int nb_fils
   \return Noeuds
*/
Noeud constructeur_noeud(Plateau p,unsigned int nb_fils){
    Noeud nd=(Noeud)malloc(sizeof(struct _noeud));
    nd->nb_fils=nb_fils;
    nd->poids_j1=-1;
    nd->poids_j2=-1;
    nd->plateau=p;
    nd->fils=(Noeud*)malloc(sizeof(Noeud)*nb_fils);
    nd->est_une_feuille=false;
    return nd;
}
/*!
   \brief Determine un nombre representant les chance de gagné pour un Joueur
   \param Arbre_solveur
   \return int
*/
int potentiel_gagnant_joueur1(Arbre_solveur as){
    return as->nb_possibilite_gagnante_j1;
}

/*!
   \brief Determine un nombre representant les chance de gagné pour un Joueur
   \param Arbre_solveur
   \return int
*/
int potentiel_gagnant_joueur2(Arbre_solveur as){
    return as->nb_possibilite_gagnante_j2;
}

/*!
   \brief constructeur de l'arbre avec le Plateau p
   \param Plateau p
   \return Arbre_solveur
*/
Arbre_solveur constructeur_arbre_solveur(Plateau p){
    Arbre_solveur as=(Arbre_solveur)malloc(sizeof(struct _arbre_possibilites));
    unsigned int dim=Dimention_plateau(p)*Dimention_plateau(p)-(liste_taille(Historique_Joueur(Joueur1(p)))+liste_taille(Historique_Joueur(Joueur2(p))));
    as->sentinelle=constructeur_noeud(copie_de_plateau(p),dim);
    as->p=p;
    as->nb_possibilite_gagnante_j1=0;
    as->nb_possibilite_gagnante_j2=0;
    //On commence à construire l'arbre à partir du jeu dans l'etat présent, et on commence par tour du joueur suivant
    if(liste_taille(Historique_Joueur(Joueur1(p)))==liste_taille(Historique_Joueur(Joueur2(p))))
    feed_arbre_solveur_rec(p,as,as->sentinelle,dim-1,0);
    else
    feed_arbre_solveur_rec(p,as,as->sentinelle,dim-1,1);
    return as;
}

/*!
   \brief Fonction recusive permetant de remplir l'arbre avec toute les possibilté d'une grille à un état donnée
   \param Plateau p
   \param Arbre_solveur as
   \param Noeuds nd noeud courant
   \param Difference entre la dimansion d'une grille et le nombre pion deja posé
   \param int joueur, On represente maintenant les joueurs par des numero pour un question de simplicité d'ecriture
   \return "Return of the function"
*/
void feed_arbre_solveur_rec(Plateau p,Arbre_solveur as,Noeud nd,unsigned int possibilites,int joueur){
    if (
        possibilites>=0
    ) {
        unsigned int nb_fils=0;
        for (unsigned int i = 0; i < Dimention_plateau(p); i++) {
            for (unsigned int j = 0; j < Dimention_plateau(p); j++) {
                //Parcours des cases vides

                if(Case_Vide(p,Coord(i,j))){
                    //Construction d'un noeud pour chaque possibilites
                    nd->fils[nb_fils]=constructeur_noeud(copie_de_plateau(p),possibilites);
                    nd->fils[nb_fils]->c=Coord(i,j);
                    if(joueur==0){
                        nd->fils[nb_fils]->j=1;
                        poser_un_pion(nd->fils[nb_fils]->plateau,Joueur1(nd->fils[nb_fils]->plateau),Coord(i,j));
                        if(Existe_Gangnant(nd->fils[nb_fils]->plateau)){
                            nd->fils[nb_fils]->est_une_feuille=true;
                            nd->fils[nb_fils]->poids_j1=possibilites;
                            (as->nb_possibilite_gagnante_j1)++;
                        }
                        else
                        feed_arbre_solveur_rec(nd->fils[nb_fils]->plateau,as,nd->fils[nb_fils],possibilites-1,1);

                    }
                    else{
                        nd->fils[nb_fils]->j=2;
                        poser_un_pion(nd->fils[nb_fils]->plateau,Joueur2(nd->fils[nb_fils]->plateau),Coord(i,j));
                        if(Existe_Gangnant(nd->fils[nb_fils]->plateau)){
                            nd->fils[nb_fils]->est_une_feuille=true;
                            nd->fils[nb_fils]->poids_j2=possibilites;
                            (as->nb_possibilite_gagnante_j2)++;
                        }
                        else
                        feed_arbre_solveur_rec(nd->fils[nb_fils]->plateau,as,nd->fils[nb_fils],possibilites-1,0);
                    }
                    nb_fils++;
                }



            }
        }
    }
}


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
void application_minmax_rec(Arbre_solveur as,Noeud nd,int *j1,int *j2){
    int j1max=0,j2max=0;
    int r_j1max,r_j2max;

    if( nd->est_une_feuille ){
        if(nd->j==1){
            //Le poinds d'un feuille est le nombre de possibilité restantes du jeux
            *j1=nd->poids_j1+10;
            *j2=0;
        }
        if(nd->j==2){
            *j1=0;
            *j2=nd->poids_j2+10;
        }
        // printf("j1=%d,j2=%d\n",nd->poids_j1,nd->poids_j2);
    }
    else{
        for (size_t i = 0; i < nd->nb_fils; i++) {
            //Recherche des maximun
            application_minmax_rec(as, nd->fils[i],&r_j1max,&r_j2max);
            if( j1max <  r_j1max )j1max=r_j1max;
            if( j2max <  r_j2max )j2max=r_j2max;

        }
        *j1=j1max;
        *j2=j2max;
    }
}

/*!
   \brief Cette fonction sert d'appel à la fonction récursive
   \param Arbre_solveur as
*/
void application_minmax(Arbre_solveur as){
    int j1,j2;
    application_minmax_rec(as,as->sentinelle,&j1,&j2);
    as->sentinelle->poids_j1=j1;
    as->sentinelle->poids_j2=j2;
}

// void affichage_minmax_rec(Noeud nd){
//     if(nd->est_une_feuille==false){
//         for (size_t i = 0; i < nd->nb_fils; i++) {
//             affichage_minmax_rec(nd->fils[i]);
//
//         }
//
//     }
//     printf("j1=%d,j2=%d\n",nd->poids_j1,nd->poids_j2);
// }
//
//
// void affichage_minmax(Arbre_solveur as){
//     printf("ffichage MINMAX\n" );
//     affichage_minmax_rec(as->sentinelle);
//
// }
//

/*!
   \brief Cette fonction sert à effectuer un copier du plateua pour pouvoir le duplique dans un arbre
   \param Plateau p
   \return Plateau
*/
Plateau copie_de_plateau(Plateau p){

    Joueur j1=contructeur_Joueur();
    Joueur j2=contructeur_Joueur();
    Plateau pnew=constructeur_plateau(Dimention_plateau(p),j1,j2);

    ListeItr itr_historique_joueur1,itr_historique_joueur2;

    itr_historique_joueur1=constructeur_liste_iterateur(Historique_Joueur(Joueur1(p)),FIFO);
    itr_historique_joueur2=constructeur_liste_iterateur(Historique_Joueur(Joueur2(p)),FIFO);

    start_liste_iterateur(itr_historique_joueur1);
    start_liste_iterateur(itr_historique_joueur2);
    Case cas;
    Coordonnee cd;

    while(!fin_liste_iterateur(itr_historique_joueur1) || !fin_liste_iterateur(itr_historique_joueur2) ){

        if(!fin_liste_iterateur(itr_historique_joueur1)){
            cas=(Case)liste_iterateur_courant(itr_historique_joueur1);
            cd=Coordonne_de_la_Case(cas);
            poser_un_pion(pnew,j1,cd);
            suivant_liste_iterateur(itr_historique_joueur1);
        }
        if(!fin_liste_iterateur(itr_historique_joueur2)){
            cas=(Case)liste_iterateur_courant(itr_historique_joueur2);
            cd=Coordonne_de_la_Case(cas);
            poser_un_pion(pnew,j2,cd);
            suivant_liste_iterateur(itr_historique_joueur2);

        }
    }
    freed_liste_iterateur(itr_historique_joueur1);
    freed_liste_iterateur(itr_historique_joueur2);
    return pnew;

}


/*!
   \brief libération d'un noeud
   \param Noeuds
*/
void freed_noeud(Noeud nd){

    freed_all(nd->plateau);
    free(nd->fils);
    free(nd);
}
/*!
   \brief Libération Noeud récursif
   \brief libération d'un noeud
   \param Noeuds

*/
void freed_noeud_rec(Noeud nd){

    if(nd->est_une_feuille==false){
        for (size_t i = 0; i < nd->nb_fils; i++) {
            freed_noeud_rec(nd->fils[i]);
        }
    }
    freed_noeud(nd);
}
/*!
   \brief Libere l'arbre
   \param Arbre Solveur

*/
void freed_arbre_solveur(Arbre_solveur as){
    freed_noeud_rec(as->sentinelle);
    free(as);
}

//
// void affichage_plateau(Plateau p){
//     assert(p);
//     printf("=======================\n" );
//     for (int i = 0; i < Dimention_plateau(p); i++) {
//         for (size_t h = 0; h < i; h++) {
//             printf("  " );
//         }
//         for (int j = 0; j < Dimention_plateau(p); j++) {
//             if(!Case_Vide(p,Coord(i,j))){
//                 if(Joueur_du_groupe( Groupe_de_la_Case( Case_de_la_Coordonnee(p,Coord(i,j)) ) )==Joueur1(p))
//                     printf("\\ o " );
//                 else
//                     printf("\\ 1 " );
//             }
//             else printf("\\ . " );
//         }
//         printf("\\\n" );
//     }
//     printf("----------------------\n" );
// }


//
// void affichage_as_rec(Noeud nd){
//
//     affichage_plateau(nd->plateau);
//     if(nd->est_une_feuille==false){
//
//         for (unsigned int i = 0; i < nd->nb_fils; i++) {
//              affichage_as_rec(nd->fils[i]);
//         }
//     }
// }
// void affichage_as(Arbre_solveur as){
//     printf("AFFICHAGE RECURSIF\n" );
//     affichage_as_rec(as->sentinelle);
//
//
// }
