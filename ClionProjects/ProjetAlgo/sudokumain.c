#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"


int main(int argc, char *argv[]) {
    int choix;
    int c = 0;
    int x = 0;
    int i = 0;
    int chiffre;
    FILE *fichier = NULL;
    int valfichier[MAXGRILLE];
    printf("------ 0 - Mode pas à pas ?------\n");
    printf("------ 1 - Mode normal avec possibilité d'utilisation de fichier pour la grille ?------\n");
    scanf("%d", &choix);
    switch (choix) {
        case 0:
            if (argc > 1) {
                fichier = fopen(argv[1], "r");
                if (fichier == NULL){ printf("Impossible d'ouvrir le fichier données en lecture\n"); exit(1);}

                while (!feof(fichier) && i < 81) {
                    fscanf(fichier, "%d ", &x);
                    valfichier[i] = x;
                    i++;


                }
                initialiserVal(valfichier);
            } else {
                printf("Pas de paramètre.\nUtilisation de la grille du programme");
                initialiser();
            }


            for (int i = 0; i < 50; i++) {
                for (int j = 0; j < MAXGRILLE; j++) {
                    R1(j, &c);
                    R2(j);
                    R3Ligne(j, &c);
                    R3Colonne(j, &c);
                    R3Region(j, &c);
                    if (c > 0) {
                        printf("\n");
                        printf("\n");
                        afficher();
                        getchar();
                    }
                    c = 0;
                }

            }
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            afficher();

            break;


        case 1:
            if (argc > 1) {
                fichier = fopen(argv[1], "r");
                if (fichier == NULL){ printf("Impossible d'ouvrir le fichier données en lecture\n"); exit(1);}

                while (!feof(fichier) && i < 81) {
                    fscanf(fichier, "%d ", &x);
                    valfichier[i] = x;
                    i++;


                }
                initialiserVal(valfichier);

            } else {
                printf("Utilisation de la grille écrite dans le programme");
                initialiser();
            }

            afficher();
            printf("\n");
            printf("\n");
            for (int i = 0; i < 1000; i++) {
                for (int j = 0; j < MAXGRILLE; j++) {

                    R1(j, &c);
                    R2(j);

                    R3Ligne(j, &c);
                    R2(j);
                    R3Colonne(j, &c);
                    R2(j);
                    R3Region(j, &c);
                    R2(j);



                }


            }

            for (int i = 0; i < 1000; i++) {
                for (int j = 0; j < MAXGRILLE; j++) {

                    R1(j, &c);
                    R2(j);

                    R3Ligne(j, &c);
                    R2(j);
                    R3Colonne(j, &c);
                    R2(j);
                    R3Region(j, &c);
                    R2(j);
                    R4Ligne(valReg(j));
                    R2(j);

                }


            }


            printf("\n");
            printf("\n");

            afficher();
            break;
        default :
            break;
    }


}


