/*!
   \file Plateau.c
   \brief Plateau.c
   \author Sylvain DEKER
   \date 11/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Plateau.h"
#define NB_JOUEUR 2

struct _joueur{
    Liste list_groupe;
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

///////////////////////////////////Constructeur / Liberateur
Joueur contructeur_Joueur(){
    Joueur new=(Joueur)malloc(sizeof(struct _joueur));
    new->list_groupe=constructeur_liste();
    return new;
}
void freed_Joueur(Joueur j){
    freed_liste(j->list_groupe);
    free(j);
}

void ajouter_groupe_a_un_joueur(Joueur j,Groupe g){
    ajout_liste(j->list_groupe,g);
}

Groupe constructeur_groupe(Joueur j){
    Groupe new=(Groupe)malloc(sizeof(struct _groupe));
    new->list_case=constructeur_liste();
    new->joueur=j;
    new->connecter_au_mur1=false;
    new->connecter_au_mur2=false;
    return new;
}

void freed_groupe(Groupe p){
    freed_liste(p->list_case);

    free(p);
}

Case constructeur_case(Coordonnee c){
    Case new=(Case)malloc(sizeof(struct _case));
    new->c=c;
    new->groupe=NULL;
    return new;
}

void freed_case(Case ca){
    free(ca);
}



Plateau constructeur_plateau(unsigned int taille_grille, Joueur j1,Joueur j2){
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



void freed_all(Plateau p){
    for (size_t i = 0; i < NB_JOUEUR; i++) {
        while(!liste_vide(p->joueur[i]->list_groupe)){

            Groupe grp=(Groupe)retirer_liste(p->joueur[i]->list_groupe,"listemode");
            freed_groupe(grp);
            // free(grp);
        }
        freed_Joueur(p->joueur[i]);
    }
    freed_plateau(p);



}
////////////////////////////////////////////////////////OPERATEURS

Coordonnee Coordonnee_Case(Case ca){
    return ca->c;
}

Groupe Groupe_de_la_Case(Case ca){
    return ca->groupe;
}

bool check_case_vide(Plateau p,Coordonnee c){
    return p->cellule[c.x][c.y]->groupe==NULL;
}

void ajouter_case_a_un_groupe(Groupe g,Case ca){
    ajout_liste(g->list_case,ca);
}





Case poser_un_pion(Plateau p, Joueur j,Coordonnee c){
    assert(p->cellule[c.x][c.y]->groupe==NULL);//Check emplacement libre
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
            Case c_vois=retirer_liste(voisin,"listemode");
            Groupe g1 = Groupe_de_la_Case(p->cellule[c.x][c.y]);
            Groupe g2 = Groupe_de_la_Case(c_vois);
            if(g1!=g2){

                fusionner_groupe(Groupe_de_la_Case(p->cellule[c.x][c.y]),Groupe_de_la_Case(c_vois));
            }
        }


    freed_liste(voisin);
    return p->cellule[c.x][c.y];
}

Joueur joueur_de_case(Case ca){
    assert(ca->groupe);
    return ca->groupe->joueur;
}




void fusionner_groupe(Groupe g1, Groupe g2){
    assert(g1!=g2);
    Joueur j=g1->joueur;
    if(g2->connecter_au_mur1)g1->connecter_au_mur1=true;
    if(g2->connecter_au_mur2)g1->connecter_au_mur2=true;
    ListeItr itera = constructeur_liste_iterateur(g2->list_case);
    for(start_liste_iterateur(itera);!fin_liste_iterateur(itera);suivant_liste_iterateur(itera)){

        Case ca=(Case)liste_iterateur_courant(itera);
        ca->groupe=g1;

    }
    liste_fusion(g1->list_case,g2->list_case);
    supprim_element_liste(j->list_groupe,g2);
    freed_liste_iterateur(itera);
    freed_groupe(g2);
}



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








//////////////////////////////////////////////////////DEV
void afficher_plateau(Plateau p){
    assert(p);
    printf("================================================\n" );
    for (int i = 0; i < p->dim; i++) {
        for (size_t h = 0; h < i; h++) {
            printf("  " );
        }
        for (int j = 0; j < p->dim; j++) {
            if(p->cellule[i][j]->groupe){
                if(p->cellule[i][j]->groupe->joueur==p->joueur[0])
                    printf("\\ o " );
                else
                    printf("\\ 1 " );
            }
            else printf("\\ . " );
        }
        printf("\\\n" );
    }
    printf("================================================\n" );
}


void bilan(Plateau p){
    ListeItr itr_grp,itr_case;
    for (int i = 0; i < NB_JOUEUR; i++) {

        printf("joueur %d = %p\n",i,p->joueur+i);
        itr_grp=constructeur_liste_iterateur(p->joueur[i]->list_groupe);
        for(start_liste_iterateur(itr_grp);!fin_liste_iterateur(itr_grp);suivant_liste_iterateur(itr_grp)){

                Groupe g=(Groupe)liste_iterateur_courant(itr_grp);
                printf("Groupe: %p  ",g );
                if(g->connecter_au_mur1)printf("Mur1 ");
                if(g->connecter_au_mur2)printf("Mur2 ");
                printf(": ");
            itr_case=constructeur_liste_iterateur(g->list_case);
            for(start_liste_iterateur(itr_case);!fin_liste_iterateur(itr_case);suivant_liste_iterateur(itr_case)){

                Case ca=(Case)liste_iterateur_courant(itr_case);
                Coordonnee co = Coordonnee_Case(ca);
                printf("\t(%d,%d)",co.x,co.y );

            }
            printf("\n");
            freed_liste_iterateur(itr_case);
        }
        freed_liste_iterateur(itr_grp);
        printf("---------------\n" );
    }



}
