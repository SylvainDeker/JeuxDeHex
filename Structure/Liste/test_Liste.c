/*!
   \file Liste.c
   \brief Utilisation de la liste avec une structure linéaire de int(Par exemple)
   \author Sylvain DEKER
   \date 10/04/2017
*/

#include "Liste.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {


    /*Création d'elements avec leur adresse (ici un simple tableau dynamique)*/

    int *tableau_de_test=(int*)malloc(sizeof(int)*10);
    for (size_t i = 0; i < 10; i++) {
        tableau_de_test[i]=i;
    }


    /*Construction de la liste*/
    Liste masuperliste=constructeur_liste();
    Liste masuperliste2=constructeur_liste();
    //Ajout de l'adresse des elements du tableau de int à la liste
    for (size_t i = 0; i < 10; i++) {
        printf("Ajout de %p (%d)\n",tableau_de_test+i,tableau_de_test[i] );
        ajout_liste(masuperliste,tableau_de_test+i);
        ajout_liste(masuperliste2,tableau_de_test+i);
    }
    //Opération sur les listes
    liste_fusion(masuperliste,masuperliste2);
    supprim_element_liste(masuperliste,tableau_de_test+0);

    //Lecture des nombres du tablea associé au adresse stocké par la liste
    ListeItr i=constructeur_liste_iterateur(masuperliste,"fifo");
    for (start_liste_iterateur(i);!fin_liste_iterateur(i);suivant_liste_iterateur(i)) {

        printf("itr=%d\n",*((int*)liste_iterateur_courant(i)) );//Ne pas oublier le cast !
    }

    //Information divers
    printf("TAILLE/ %u\n",liste_taille(masuperliste) );
    printf("TAILLE/ %u\n",liste_taille(masuperliste2) );

    //Libérateurs
    freed_liste_iterateur(i);
    freed_liste(masuperliste);
    freed_liste(masuperliste2);

    //Libartion de structure de test
    free(tableau_de_test);


    return 0;
}
