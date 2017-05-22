
/*!
   \file Pont.c
   \brief
   \author Sylvain DEKER
   \date 14/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Pont.h"
#define MAXINT 42949600


struct _couple{
    Groupe **matrice;
};

struct _pont{
    Coordonnee c;
    struct _couple*cple_ile;
    int poids;
};










// Pont constructeur_Pont(Coordonnee c, int poids){
//     Pont pt= (Pont)malloc(sizeof(struct _pont));
//     pt->c=c;
//     pt->poids=poids;
// }
//
//
//
//
//
//
//
//
//
//
// int deux_voisin_de_groupe_different(Plateau p,Joueur jr,Coordonnee in, Coordonnee *out1,Coordonnee *out2 ){
//     int i=0;
//     int j=0;
//     int found=0;
//     while(i<6){
//         while(j<6){
//
//             Coordonnee vi = Coord_voisin(in,i);
//             Coordonnee vj = Coord_voisin(in,j);
//             // printf("vi=%d,%d vj=%d,%d\n",vi.x,vi.y,vj.x,vj.y );
//             if( Coord_valide(vi,0,Dimention_plateau(p))&&Coord_valide(vj,0,Dimention_plateau(p)) && !Case_Vide(p,vi)&&!Case_Vide(p,vj) ){
//
//
//                 Groupe g1=Groupe_de_la_Case(Case_de_la_Coordonnee(p,vi));
//                 Groupe g2=Groupe_de_la_Case(Case_de_la_Coordonnee(p,vj));
//
//                 if( g1!=g2 && Joueur_du_groupe(g1)==jr && Joueur_du_groupe(g2)==jr ){
//                     out1->x=vi.x;
//                     out1->y=vi.y;
//                     out2->x=vj.x;
//                     out2->y=vj.y;
//                     found++;
//                 }
//             }
//             j++;
//         }
//         j=0;
//         i++;
//     }
//
//     return found;
// };
//
//
//
// int groupe_forme_pont(Plateau p,Groupe p1,Groupe p2,Coordonnee *out1,Coordonnee *out2){
//     assert(p1!=p2);
//     assert(Joueur_du_groupe(p1)==Joueur_du_groupe(p2));
//     ListeItr itr1=constructeur_liste_iterateur(Liste_Case_du_Groupe(p1),FIFO);
//     ListeItr itr2=constructeur_liste_iterateur(Liste_Case_du_Groupe(p2),FIFO);
//
//     Case i,j;
//     int distancemax=MAXINT;
//     for(start_liste_iterateur(itr1); !fin_liste_iterateur(itr1); suivant_liste_iterateur(itr1)){
//         i=(Case)liste_iterateur_courant(itr1);
//         Coordonnee c1 = Coordonne_de_la_Case(i);
//
//         for(start_liste_iterateur(itr2); !fin_liste_iterateur(itr2); suivant_liste_iterateur(itr2)){
//
//             j=(Case)liste_iterateur_courant(itr2);
//             Coordonnee c2 = Coordonne_de_la_Case(j);
//             // printf("Calcul :%d hh %d,%d %d,%d\n",((c2.x-c1.x)*(c2.x-c1.x)+(c2.y-c1.y)*(c2.y-c1.y)),c1.x,c1.y,c2.x,c2.y );
//             if( ((c2.x-c1.x)*(c2.x-c1.x)+(c2.y-c1.y)*(c2.y-c1.y)) < distancemax ){
//                 out1->x=Coordonne_de_la_Case(i).x;
//                 out1->y=Coordonne_de_la_Case(i).y;
//                 out2->x=Coordonne_de_la_Case(j).x;
//                 out2->y=Coordonne_de_la_Case(j).y;
//                 distancemax=((c2.x-c1.x)*(c2.x-c1.x)+(c2.y-c1.y)*(c2.y-c1.y));
//             }
//         }
//     }
//
//     freed_liste_iterateur(itr1);
//     freed_liste_iterateur(itr2);
//
//     int res;
//     if(Joueur_du_groupe(p1)==Joueur1(p))
//         res=deux_voisin_de_groupe_different()
// }
