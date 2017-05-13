/*!
   \file test_Plateau.c
   \brief test_Plateau.c
   \author Sylvain DEKER
   \date 1/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "../Plateau/Plateau.h"
#include "../Sauvegarde/Sauvegarde.h"
#define TAILLE_PLAT 8


void afficher_plateau(Plateau p);
void bilan(Plateau p);
void afficher_menu(int *c, Plateau p, char* name1, char* name2);

int main(int argc, char const *argv[]) {
    int c = 0;
    char name1;
    char name2;
    Joueur un=contructeur_Joueur();
    Joueur deux=contructeur_Joueur();

    Plateau p=constructeur_plateau(TAILLE_PLAT,un,deux);

    afficher_menu(&c, p, &name1, &name2);

    
    freed_all(p);
    return 0;
}



void afficher_menu(int *c, Plateau p, char* name1, char* name2){
  int choice = -1;

  char *nameFile = NULL;
  system("clear");
  printf("\t1 - New game\n");
  printf("\t2 - Restore game\n\n");
  printf("\tWhat do you want to do ? ");


  scanf("%d", &choice);
  switch (choice) {
    case 1:
      system("clear");
      printf("\t1 - Human vs Human \n");
      printf("\t2 - Human vs AI \n\n");
      printf("\tWhat do you want to do ? ");
      scanf("%d", &choice);
      switch (choice) {
        case 1 :
          printf("\tWhat is the name of the first player ? ");
          scanf("%s", name1);
          printf("\tPLAYER 1 : %s\n", name1);
          printf("\tWhat is the name of the second player ? ");
          scanf("%s", name2);
          printf("\tPLAYER 2 : %s\n", name2);
          break;
        case 2 :
        printf("\tWhat is the name of the player ? ");
        scanf("%s", name1);

      }
      break;
      //LANCER PARTIE SELON CHOIX

    case 2 :
      printf("\tWhat is the name of the file to restore ? ");
      scanf("%s", nameFile);
      restaurer_partie(nameFile, &p);
      //REPRENDRE LE JEU
      afficher_plateau(p);
  }


}





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


    printf("Joueur 0\n");
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

    printf("Joueur 1\n");
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