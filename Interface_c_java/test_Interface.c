/*!
   \file test_Interface.c
   \brief
   \author Sylvain DEKER
   \date 17/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Interface.h"
#define TAILLE_PLAT 8

int main(int argc, char const *argv[]) {


    Joueur patrick=contructeur_Joueur();
    Joueur robert=contructeur_Joueur();
    Plateau p=constructeur_plateau(TAILLE_PLAT,patrick,robert);
    // envoyer_grille(p);//faire "cat c_vers_java" dans un autre terminal pour debloquer
    // envoyer_existe_gagnant(p); //faire "cat c_vers_java" dans un autre terminal pour debloquer
    char *ordre=(char*)malloc(sizeof(char)*255);
    lecture_requete(ordre); // echo "blablabla" > java_vers_c
    printf("Ordre recu %s\n",ordre );

    return 0;
}
