
/*!
   \file test_Arbre.c
   \brief test_Arbre.c
   \author Sylvain DEKER
   \date 13/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Pont.h"

#define TAILLE_PLAT 6




void afficher_plateau(Plateau p);
void bilan(Plateau p);
void test_pont(Plateau p);

int main(int argc, char const *argv[]) {

    Joueur patrick=contructeur_Joueur();
    Joueur robert=contructeur_Joueur();
    Plateau p=constructeur_plateau(TAILLE_PLAT,patrick,robert);

    // srand(20);
    // int x=0,y=0;
    //
    // for (size_t i = 0; i < 2; i++) {
    // // while(!Existe_Gangnant(p)){
    //
    //     while (!Case_Vide(p,Coord(x,y)) ){
    //         x=rand()%Dimention_plateau(p);
    //         y=rand()%Dimention_plateau(p);
    //     }
    //     poser_un_pion(p, Joueur1(p), Coord(x,y) );
    //
    //     while (!Case_Vide(p,Coord(x,y)) ){
    //         x=rand()%Dimention_plateau(p);
    //         y=rand()%Dimention_plateau(p);
    //     }
    //     if(!Existe_Gangnant(p))
    //         poser_un_pion(p,Joueur2(p),Coord(x,y));
    //
    //
    // }

    // for (size_t i = 0; i < 12; i++) {
    //     if(Coord_valide(Coord_pont(Coord(3,3),i),0,Dimention_plateau(p)))
    //         poser_un_pion(p,Joueur1(p),Coord_pont(Coord(3,3),i));
    // }
    Coordonnee a= Coord(0,0);
    Coordonnee b= Coord(0,1);
    Coordonnee c= Coord(0,3);
    Coordonnee d= Coord(0,4);
    Coordonnee e= Coord(2,0);


    poser_un_pion(p,Joueur1(p),a);
    poser_un_pion(p,Joueur1(p),b);
    poser_un_pion(p,Joueur1(p),c);
    poser_un_pion(p,Joueur1(p),d);
    poser_un_pion(p,Joueur1(p),e);

    afficher_plateau(p);
    // bilan(p);
    // Coordonnee out1;
    // Coordonnee out2;
    // int res=deux_voisin_de_groupe_different( p,Joueur1(p),Coord(1,0), &out1,&out2 );
    // if(res)
    //     printf("Cood res= %d :%d,%d   %d,%d\n",res,out1.x,out1.y,out2.x,out2.y );
    //
    // Liste pontj1=constructeur_liste();
    // Liste pontj2=constructeur_liste();


    // test_pont(p);
    // int res=forme_pond( p, a, b);
    // printf("%d\n",res );












    freed_all(p);










    return 0;
}

void test_pont(Plateau p){
    ListeItr itr1=constructeur_liste_iterateur(Liste_Groupe_du_Joueur(Joueur1(p)),FIFO);
    ListeItr itr2=constructeur_liste_iterateur(Liste_Groupe_du_Joueur(Joueur1(p)),FIFO);

    Groupe i,j;
    for(start_liste_iterateur(itr1);!fin_liste_iterateur(itr1);suivant_liste_iterateur(itr1)){
        i=(Groupe)liste_iterateur_courant(itr1);

        for(start_liste_iterateur(itr2);!fin_liste_iterateur(itr2);suivant_liste_iterateur(itr2)){
            j=(Groupe)liste_iterateur_courant(itr2);
            if(i!=j){

                Coordonnee out1,out2;
                int res=groupe_forme_pont(p,i,j,&out1,&out2);

                if(res)
                    printf("Pont entre %d,%d et %d,%d\n",out1.x,out1.y,out2.x,out2.y );
            }
        }
    }
    freed_liste_iterateur(itr1);
    freed_liste_iterateur(itr2);

}


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


void afficher_plateau(Plateau p){
    assert(p);
    printf("================================================\n" );
    for (int i = 0; i < Dimention_plateau(p); i++) {
        for (size_t h = 0; h < i; h++) {
            printf("  " );
        }
        for (int j = 0; j < Dimention_plateau(p); j++) {
            if(!Case_Vide(p,Coord(i,j))){
                if(Joueur_du_groupe( Groupe_de_la_Case( Case_de_la_Coordonnee(p,Coord(i,j)) ) )==Joueur1(p))
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


    printf("joueur 0\n");
    itr_grp=constructeur_liste_iterateur(Liste_Groupe_du_Joueur(Joueur1(p)),FIFO);
    for(start_liste_iterateur(itr_grp);!fin_liste_iterateur(itr_grp);suivant_liste_iterateur(itr_grp)){

            Groupe g=(Groupe)liste_iterateur_courant(itr_grp);
            printf("Groupe: %p  ",g );
            if(Groupe_co_au_mur1(g))printf("Mur1 ");
            if(Groupe_co_au_mur2(g))printf("Mur2 ");
            printf(": ");
        itr_case=constructeur_liste_iterateur(Liste_Case_du_Groupe(g),FIFO);
        for(start_liste_iterateur(itr_case);!fin_liste_iterateur(itr_case);suivant_liste_iterateur(itr_case)){

            Case ca=(Case)liste_iterateur_courant(itr_case);
            Coordonnee co = Coordonne_de_la_Case(ca);
            printf("\t(%d,%d)",co.x,co.y );

        }
        printf("\n");
        freed_liste_iterateur(itr_case);
    }
    freed_liste_iterateur(itr_grp);
    printf("---------------\n" );

    printf("joueur 1\n");
    itr_grp=constructeur_liste_iterateur(Liste_Groupe_du_Joueur(Joueur2(p)),FIFO);
    for(start_liste_iterateur(itr_grp);!fin_liste_iterateur(itr_grp);suivant_liste_iterateur(itr_grp)){

            Groupe g=(Groupe)liste_iterateur_courant(itr_grp);
            printf("Groupe: %p  ",g );
            if(Groupe_co_au_mur1(g))printf("Mur1 ");
            if(Groupe_co_au_mur2(g))printf("Mur2 ");
            printf(": ");
        itr_case=constructeur_liste_iterateur(Liste_Case_du_Groupe(g),FIFO);
        for(start_liste_iterateur(itr_case);!fin_liste_iterateur(itr_case);suivant_liste_iterateur(itr_case)){

            Case ca=(Case)liste_iterateur_courant(itr_case);
            Coordonnee co = Coordonne_de_la_Case(ca);
            printf("\t(%d,%d)",co.x,co.y );

        }
        printf("\n");
        freed_liste_iterateur(itr_case);
    }
    freed_liste_iterateur(itr_grp);
    printf("---------------\n" );

    if(Existe_Gangnant(p))printf("Joueur gagnant : %p\n",Existe_Gangnant(p) );




    printf("Historique joueur 0\n" );
    ListeItr itr_histo;
    itr_histo=constructeur_liste_iterateur(Historique_Joueur(Joueur1(p)),FIFO);
    for(start_liste_iterateur(itr_histo);!fin_liste_iterateur(itr_histo);suivant_liste_iterateur(itr_histo)){

        Case cas=(Case)liste_iterateur_courant(itr_histo);
        Coordonnee cd = Coordonne_de_la_Case(cas);
        printf("(%d,%d) ",cd.x,cd.y );

    }
    printf("\n");
    freed_liste_iterateur(itr_histo);
    printf("Historique joueur 1\n" );
    itr_histo=constructeur_liste_iterateur(Historique_Joueur(Joueur2(p)),FIFO);
    for(start_liste_iterateur(itr_histo);!fin_liste_iterateur(itr_histo);suivant_liste_iterateur(itr_histo)){

        Case cas=(Case)liste_iterateur_courant(itr_histo);
        Coordonnee cd = Coordonne_de_la_Case(cas);
        printf("(%d,%d) ",cd.x,cd.y );

    }
    printf("\n");
    freed_liste_iterateur(itr_histo);

}
