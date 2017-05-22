/*!
   \file Plateau.c
   \brief Structure de Donnée de Joueur, Groupe, Plateau, Case.
   \author Sylvain DEKER
   \date 11/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Plateau.h"
#define NB_JOUEUR 2

struct _joueur{
    Liste list_groupe;
    Liste list_historique_case;
};

struct _groupe{
    Joueur joueur;
    Liste list_case;
    bool connecter_au_mur1;
    bool connecter_au_mur2;
};

struct _plateau{
    unsigned int dim;//dimention
    Case**cellule;
    Joueur joueur[NB_JOUEUR];
};

struct _case{
    Coordonnee c;
    Groupe groupe;
};




void freed_Joueur(Joueur j);
void freed_plateau(Plateau p);
void voisin_etant_du_joueur(Plateau p,Joueur j,Coordonnee c, Liste l );
bool Case_Vide(Plateau p,Coordonnee c);
void fusionner_groupe(Groupe g1, Groupe g2);
void ajouter_groupe_a_un_joueur(Joueur j,Groupe g);

///////////////////////////////////Constructeur / Liberateur
/*!
   \brief Constructeur Joueur
   \return Joueur
*/
Joueur contructeur_Joueur(){
    Joueur new=(Joueur)malloc(sizeof(struct _joueur));
    new->list_groupe=constructeur_liste();//Construction d'une Liste de Groupe
    new->list_historique_case=constructeur_liste();//Construction d'une Liste de Case (sert d'historique pour la sauvegarde et la restauration)
    return new;
}

/*!
   \brief Permet de libere la structure Joueur et les structure liste qu'il contient (mais ne libere pas le contenu des listes)
   \param Joueur j
*/
void freed_Joueur(Joueur j){
    freed_liste(j->list_groupe);
    freed_liste(j->list_historique_case);
    free(j);
}

/*!
   \brief Constructeur de Groupe.
        Un groupe est un enssemble de case regroupé selon les regles decrites dans Document spécification.
        Un joueur possede plusieur groupe
        Il ya au minimum une case dans un groupe
   \param Joueur j Associé
   \pre "Pre-conditions"
   \post "Post-conditions"
   \return "Return of the function"
*/
Groupe constructeur_groupe(Joueur j){
    Groupe new=(Groupe)malloc(sizeof(struct _groupe));
    new->list_case=constructeur_liste();
    new->joueur=j;
    new->connecter_au_mur1=false;
    new->connecter_au_mur2=false;
    return new;
}

/*!
   \brief Libérateur de Groupe
   \param Groupe p
*/
void freed_groupe(Groupe p){
    freed_liste(p->list_case);
    free(p);
}

/*!
   \brief Constructeur d'un Case une Case est associé à une Coordonnee unique
   \param Coordonnee
   \return Case
*/
Case constructeur_case(Coordonnee c){
    Case new=(Case)malloc(sizeof(struct _case));
    new->c=c;
    new->groupe=NULL;
    return new;
}

/*!
   \brief "Description"
   \param "Param description"
   \pre "Pre-conditions"
   \post "Post-conditions"
   \return "Return of the function"
*/
void freed_case(Case ca){
    free(ca);
}

/*!
   \brief Constructeur de structure publique  Plateau
   \param unsigned int Taille de la grille
   \Joueur j1;
   \Joueur j2;
   \return Plateau
*/
Plateau constructeur_plateau(unsigned int taille_grille, Joueur j1,Joueur j2){
    assert(taille_grille>0);
    Plateau p=(Plateau)malloc(sizeof(struct _plateau));
    p->dim=taille_grille;
    p->joueur[0]=j1;
    p->joueur[1]=j2;
    p->cellule=(Case**)malloc(sizeof(Case**)*taille_grille);
    for (size_t i = 0; i < p->dim; i++) {
        p->cellule[i]=(Case*)malloc(sizeof(Case*)*taille_grille);
        for (size_t j = 0; j < p->dim; j++) {
            p->cellule[i][j]=constructeur_case(Coord(i,j));
        }
    }
    return p;
}

/*!
   \brief Libérateur de Structure Plateau
   \param Plateau
*/
void freed_plateau(Plateau p){
    for (size_t i = 0; i < p->dim; i++) {
        for (size_t j = 0; j < p->dim; j++) {
            freed_case( p->cellule[i][j] );
        }
        free(p->cellule[i]);

    }

    free(p->cellule);
    free(p);
}


/*!
   \brief Libérateur des tous les structures de donnée de cette page (Plateau.c) associé au plateau passé en parametre (cad Plateau +Groupe +case + Joeuur)
   \param Plateau p
*/
void freed_all(Plateau p){
    for (size_t i = 0; i < NB_JOUEUR; i++) {
        while(!liste_vide(p->joueur[i]->list_groupe)){

            Groupe grp=(Groupe)retirer_liste(p->joueur[i]->list_groupe,FIFO);
            freed_groupe(grp);
            // free(grp);
        }
        freed_Joueur(p->joueur[i]);
    }
    freed_plateau(p);



}
////////////////////////////////////////////////////////OPERATEURS LOCALS
/*!
   \brief Fonction "Raccourci" permet de rajouter manuellement un groupe à un joueur
   \post Taille de liste des groupe ++ 1
*/
void ajouter_groupe_a_un_joueur(Joueur j,Groupe g){
    ajout_liste(j->list_groupe,g);
}

/*!
   \brief Ajout Manuel d'une Case ca à un Groupe g
   \param Groupe g
   \param Case ca
*/
void ajouter_case_a_un_groupe(Groupe g,Case ca){
    ajout_liste(g->list_case,ca);
}

/*!
   \brief Permet de determiner le joueur associé à la case
   \param "Param description"
   \pre "Pre-conditions"
   \post "Post-conditions"
   \return "Return of the function"
*/
Joueur joueur_de_case(Case ca){
    assert(ca->groupe);
    return ca->groupe->joueur;
}

/*!
   \brief Fonction permettant de fusionner deux groupes (en libere une et ajoute le contenue de l'une à l'autre et actualise ses branchements)
   \param Groupe g1 (Celui qui est coonservé)
   \param Groupe g2 (Celui qui est supprimé)
*/
void fusionner_groupe(Groupe g1, Groupe g2){
    assert(g1!=g2);
    Joueur j=g1->joueur;
    //si un des deux mur fusionner est connecter au mur alors le nouveau aussi
    if(g2->connecter_au_mur1)g1->connecter_au_mur1=true;
    if(g2->connecter_au_mur2)g1->connecter_au_mur2=true;
    //Pour les element de g2, on les ajoute à g1
    ListeItr itera = constructeur_liste_iterateur(g2->list_case,FIFO);
    for(start_liste_iterateur(itera);!fin_liste_iterateur(itera);suivant_liste_iterateur(itera)){

        Case ca=(Case)liste_iterateur_courant(itera);
        ca->groupe=g1;

    }
    //Fusion des liste
    liste_fusion(g1->list_case,g2->list_case);
    //Supp le groupe supprimé de la liste du joueur correspondant
    supprim_element_liste(j->list_groupe,g2);
    //Libération du groupe supprimé
    freed_liste_iterateur(itera);
    freed_groupe(g2);
}

/*!
   \brief Permet d'ajouter à la liste de cases, toutes les cases voisinens étant du meme joueir
   \param Plateau p
   \param Joueur j
   \param Coordonnee c
   \param Liste l (Case)
   \return "Return of the function"
*/

void voisin_etant_du_joueur(Plateau p,Joueur j,Coordonnee c, Liste l ){

    Coordonnee voisin;
    for (size_t i = 0; i < 6; i++) {
        voisin=Coord_voisin(c,i);
        if(Coord_valide(voisin,0,p->dim)){
            if(p->cellule[voisin.x][voisin.y]->groupe){
                if(p->cellule[voisin.x][voisin.y]->groupe->joueur == j){
                    ajout_liste(l,(Case) p->cellule[voisin.x][voisin.y]);
                }
            }
        }
    }
}



/////////////////////////////////////////////////////// OPERATEURS PUBLIQUE

/*!
   \brief Parcours le Plateau et Revoi la premiere case vide
   \param Plateau p
   \pre Au mion un emplacement de libre -> voir le assert
   \return Coordonnee emplacement libre
*/
Coordonnee Emplacement_libre(Plateau p){
    assert(liste_taille(Historique_Joueur(Joueur1(p)))+liste_taille(Historique_Joueur(Joueur2(p)))<Dimention_plateau(p)*Dimention_plateau(p)  );
    bool found =false;
    int i=0,j=0;
    while (i<Dimention_plateau(p)&& !found) {
        while (j<Dimention_plateau(p)&& !found) {

            if(Case_Vide(p,Coord(i++,j++)))found=true;

        }
    }
    return Coord(i-1,j-1);
}

/*!
   \brief Determine la Coordonnee associé à une case
   \param Case ca
   \pre La case doit appartenir au Plateau p
   \return Coordonnee
*/
Coordonnee Coordonne_de_la_Case(Case ca){
    return ca->c;
}

/*!
   \brief Determine le groupe associé à la case ca
   \param Case ca
   \pre La case doit appartnir au Plateau p
   \return Groupe ou NULL si aucun pion n'est posé sur cette case
*/
Groupe Groupe_de_la_Case(Case ca){
    return ca->groupe;
}

/*!
   \brief Determine la case de la Coordonnee c sur le Plateau p
   \param Plateau p
   \return Case
*/
Case Case_de_la_Coordonnee(Plateau p,Coordonnee c){
    return p->cellule[c.x][c.y];
}

/*!
   \brief Revoie la Liste des groupes de Cases associé au Joueur j
   \param Joueur j
   \pre
   \post
   \return Liste (Groupe)
*/
Liste Liste_Groupe_du_Joueur(Joueur j){
    return j->list_groupe;
}

/*!
   \brief Revoie la liste des Cases associé à un groupe
   \param Groupe
   \return Liste (Case)
*/
Liste Liste_Case_du_Groupe(Groupe g){
    return g->list_case;
}

/*!
   \brief Determine le Joueur d'un groupe
   \param Groupe p !=NULL
   \pre p !=NULL
   \post
   \return Joueur
*/
Joueur Joueur_du_groupe(Groupe g){
    return g->joueur;
}

/*!
   \brief Determine si un groupe est connecté au mur 1 (cad si au moins un pions appartenant à ce groupe est voisin de ce mur)
   \param Groupe p
   \pre
   \post
   \return 1= est connecter, 0sinon
*/
bool Groupe_co_au_mur1(Groupe g){
    return g->connecter_au_mur1;
}

/*!
   \brief Determine si un groupe est connecté au mur 1 (cad si au moins un pions appartenant à ce groupe est voisin de ce mur)
   \param Groupe p
   \pre
   \post
   \return 1= est connecter, 0sinon
*/
bool Groupe_co_au_mur2(Groupe g){
    return g->connecter_au_mur2;
}
/*!
   \brief Determine la dimention du Plateau
   \param Plateau
   \return unsigned int
*/
unsigned int Dimention_plateau(Plateau p){
    return p->dim;
}

/*!
   \brief Determine si une case est vide ou non²
   \param Plateau p
   \param Coordonnee
   \return 1= vide, 0 sinon
*/
bool Case_Vide(Plateau p,Coordonnee c){
    return p->cellule[c.x][c.y]->groupe==NULL;
}

/*!
   \brief Revoie l'adresse du Joueur1
   \param Plateau p
   \return Joueur
*/
Joueur Joueur1(Plateau p){
    return p->joueur[0];
}

/*!
   \brief Revoie l'adresse du Joueur2
   \param Plateau p
   \return Joueur
*/
Joueur Joueur2(Plateau p){
    return p->joueur[1];
}

/*!
   \brief "Description"
   \param "Param description"
   \pre "Pre-conditions"
   \post "Post-conditions"
   \return "Return of the function"
*/
Liste Historique_Joueur(Joueur j){
    return j->list_historique_case;
}

/*!
   \brief Pose un pion de Jouer j sur le Plateau p
   \param Plateau p
   \param Joueur j
   \param Coordonnee c
   \return Case où est poser le pion
*/
Case poser_un_pion(Plateau p, Joueur j,Coordonnee c){
    assert(p->cellule[c.x][c.y]->groupe==NULL);//Check emplacement libre
    assert(c.x >=0 && c.x<p->dim && c.y>=0 && c.y<p->dim );
    //Ajout a l'historique
    ajout_liste(j->list_historique_case,Case_de_la_Coordonnee(p,c));
    Liste voisin=constructeur_liste();
    voisin_etant_du_joueur(p,j,c,voisin);
        //Constuction d'un nouveau groupe
        p->cellule[c.x][c.y]->groupe=constructeur_groupe(j);
        ajouter_case_a_un_groupe(p->cellule[c.x][c.y]->groupe , p->cellule[c.x][c.y]);
        ajouter_groupe_a_un_joueur(j,p->cellule[c.x][c.y]->groupe);
        //On determine si il est connecter a mur

        if(p->joueur[0]==j){
            if(c.y==0) p->cellule[c.x][c.y]->groupe->connecter_au_mur1=true;
            if(c.y==p->dim-1)p->cellule[c.x][c.y]->groupe->connecter_au_mur2=true;
        }
        if(p->joueur[1]==j){
            if(c.x==0) p->cellule[c.x][c.y]->groupe->connecter_au_mur1=true;
            if(c.x==p->dim-1)p->cellule[c.x][c.y]->groupe->connecter_au_mur2=true;
        }

        //On determine si il connecter a un autre groupe

        while(!liste_vide(voisin)){
            Case c_vois=retirer_liste(voisin,FIFO);
            Groupe g1 = Groupe_de_la_Case(p->cellule[c.x][c.y]);
            Groupe g2 = Groupe_de_la_Case(c_vois);
            if(g1!=g2){

                fusionner_groupe(Groupe_de_la_Case(p->cellule[c.x][c.y]),Groupe_de_la_Case(c_vois));
            }
        }


        freed_liste(voisin);
    return p->cellule[c.x][c.y];
}

/*!
   \brief Determine si il existe un gagnant
   \param Plateau p
   \return Joueur si gagnant NULL sinon
*/
Joueur Existe_Gangnant(Plateau p){
    Joueur joueur_gagnant=NULL;
    ListeItr itr_grp;
    //Pour tout les joueur
    for (int i = 0; i < NB_JOUEUR; i++) {

        //On cherche à svoir si un groupe est connecter au 2 murs
        itr_grp=constructeur_liste_iterateur(p->joueur[i]->list_groupe,FIFO);
        for(start_liste_iterateur(itr_grp);!fin_liste_iterateur(itr_grp);suivant_liste_iterateur(itr_grp)){

            Groupe grp=liste_iterateur_courant(itr_grp);
            if(grp->connecter_au_mur1 && grp->connecter_au_mur2){
                joueur_gagnant=(Joueur)(p->joueur+i);

            }

        }
        freed_liste_iterateur(itr_grp);

    }
    return joueur_gagnant;
}
