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
    FILE *fifo=fopen("java_vers_c","r");
    lecture_flux(fifo);
    fclose(fifo);

    // Joueur patrick=contructeur_Joueur();
    // Joueur robert=contructeur_Joueur();
    // Plateau p=constructeur_plateau(TAILLE_PLAT,patrick,robert);
    // envoyer_data(p);
    return 0;
}
