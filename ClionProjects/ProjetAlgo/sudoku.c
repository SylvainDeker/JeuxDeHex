#include <stdio.h>
#include <assert.h>
#include "sudoku.h"

//Grille utilisé dans le cas où aucun fichier n'est mis en paramètre
int grille[MAXGRILLE] = {0, 0, 0, 5, 0, 0, 0, 1, 0,
                         6, 0, 5, 0, 2, 0, 0, 0, 0,
                         0, 0, 1, 8, 0, 0, 5, 0, 3,
                         0, 0, 4, 0, 6, 0, 0, 0, 1,
                         7, 0, 0, 0, 0, 0, 0, 0, 4,
                         8, 0, 0, 0, 3, 0, 6, 0, 0,
                         2, 0, 9, 0, 0, 5, 7, 0, 0,
                         0, 0, 0, 0, 8, 0, 2, 0, 5,
                         0, 6, 0, 0, 0, 9, 0, 0, 0
};
//Grille
T_sudoku sudoku;


//Initialiser la grille de sudoku avec la grille
void initialiser() {
    for (int i = 0; i < MAXGRILLE; i++) {
        //Affectation
        sudoku.grille[i].val = grille[i];
        for (int j = 0; j < MAXCANDIDATS; j++) {
            //Affectation des candidats. Si la case a une valeur,0 candidats
            if (sudoku.grille[i].val == 0) {
                sudoku.grille[i].candidats[j] = j + 1;
            } else {
                sudoku.grille[i].candidats[j] = 0;
            }

        }
        //Nombre de candidats
        sudoku.grille[i].n_candidats = 9;
    }

}

//Initialiser avec la grille du fichier en paramètre
void initialiserVal(int *v) {
    for (int i = 0; i < MAXGRILLE; i++) {
        sudoku.grille[i].val = v[i];
        for (int j = 0; j < MAXCANDIDATS; j++) {
            if (sudoku.grille[i].val == 0) {
                sudoku.grille[i].candidats[j] = j + 1;
            } else {
                sudoku.grille[i].candidats[j] = 0;
            }

        }
        //Nombre de candidats
        sudoku.grille[i].n_candidats = 9;
    }

}


void remplirgrille(){
    for(int i=0;i<MAXGRILLE;i++){
        afficher();
        printf("Veuillez entrer la valeur n°%d : ",i);
        scanf("%d",&sudoku.grille[i].val);
        for (int j = 0; j < MAXCANDIDATS; j++) {
            if (sudoku.grille[i].val == 0) {
                sudoku.grille[i].candidats[j] = j + 1;
            } else {
                sudoku.grille[i].candidats[j] = 0;
            }

        }
    }
}


//Afficher la grille
void afficher() {
    for (int i = 0; i < MAXGRILLE; i++) {
        //Espace si on passe à la region suivante
        if (i % 3 == 0) {
            printf(" ");
        }
        //Saut de ligne lorsqu'on a atteint la fin de ligne
        if (i % 9 == 0) {
            printf("\n");
        }
        printf(" %d ", sudoku.grille[i].val);

        //Séparation horizontal entre région
        if (i == 53 || i == 26) {
            printf("\n");
        }
    }
    printf("\n \n");
}

//Permet de mettre à zero les candidats des cases ayant une valeur autre que 0
void cleanup() {
    for (int i = 0; i < MAXGRILLE; i++) {
        if (sudoku.grille[i].val != 0) {
            for (int j = 0; j < MAXCANDIDATS; j++) {

                sudoku.grille[i].candidats[j] = 0;
            }
        }
    }

}


//Ligne de la première case de la région passé en paramètre
int coordCaseRegionLigne(int r) {
    assert(r >= 0 && r < 9);
    return 3 * (r / 3);

}

//Colonne de la première case de la région passé en paramètre
int coordCaseRegionColonne(int r) {
    assert(r >= 0 && r < 9);
    return 3 * (r % 3);

}

//Colonne de la case c
int valColonne(int c) {
    assert(c >= 0 && c < 81);
    return c % 9;
}

//Ligne de la case c
int valLigne(int c) {
    assert(c >= 0 && c < 81);
    return c / 9;
}

//Région de la case c
int valReg(int c) {
    assert(c >= 0 && c < 81);
    return 3 * (valLigne(c) / 3) + (valColonne(c) / 3);
}

//Indice de la case selon la ligne et la colonne
int indiceCase(int l, int c) {
    assert(c >= 0 && c < 81);
    assert(l >= 0 && l < 9);
    return (9 * l + c);
}


//Recherche de valeur v dans le tableau t de taille n
int rechercheValeur(int t[], int n, int v) {
    // i = 0
    int i = 0;
    //Inv : i >= 0
    while (i < n) {
        //i >= 0 ⋀ i<n
        assert(i >= 0 && i < n);
        if (t[i] == v) {
            return i;
        }
        i++;
        //i >= 0
        assert(i >= 0);
    }
    //i >= 0 ⋀ i>=n
    assert(i >= 0 && i >= n);
    return n;
    //i<=n
}

//Suppression de la valeur v dans le tableau t de taille n
void supprimerValeur(int t[], int n, int v) {
    // i = 0
    int i = 0;
    //Inv : i >= 0
    while (i < n) {
        //i >= 0 ⋀ i<n
        assert(i >= 0 && i < n);
        if (t[i] == v) {
            t[i] = 0;
        }
        i++;
        //i >= 0
        assert(i >= 0);
    }
    //i >= 0 ⋀ i>=n
    assert(i >= 0 && i >= n);
}

//Dans le cas ou le nbre de candidat est a 1 affectation de ce candidat à la case.
//Clicker est un compteur pour le mode pas a pas
void R1(int c, int *clicker) {
    if (sudoku.grille[c].n_candidats == 1 && sudoku.grille[c].val == 0) {
        for (int i = 0; i < MAXCANDIDATS; ++i) {
            if (sudoku.grille[c].candidats[i] != 0) {
                sudoku.grille[c].val = sudoku.grille[c].candidats[i];
                *clicker += 1;
            }
        }
        for (int j = 0; j < MAXCANDIDATS; ++j) {
            sudoku.grille[c].candidats[j]=0;
        }
    }
}

//Réduction du nombre de candidat.
//Recherche dans ligne, colonne région, des candidats déjà placés et les supprime de la case visée
void R2(int c) {
    int tcolonne[MAXCANDIDATS]; //Valeurs des cases en colonne
    int tligne[MAXCANDIDATS]; //Valeurs des case en ligne
    int tregion[MAXCANDIDATS]; // Valeur des cases en région
    //Indice de la première case de la région
    int indcase = indiceCase(coordCaseRegionLigne(valReg(c)), coordCaseRegionColonne(valReg(c)));


    //Si la case visée a déjà une valeur inutile de lancer le programme
    if (sudoku.grille[c].val == 0) {

        //Ligne
        //Valeurs de la ligne => tligne
        int j = 0;
        for (int i = 9 * (valLigne(c) + 1) - 9; i < (9 * (valLigne(c) + 1) - 9) + 9; i++) {
            tligne[j] = sudoku.grille[i].val;
            j++;
        }
        //Suppression des candidats si une valeur correspondante est déja placée dans la ligne
        for (int i = 1; i <= MAXCANDIDATS; i++) {
            if (rechercheValeur(tligne, MAXCANDIDATS, i) != MAXCANDIDATS &&
                rechercheValeur(sudoku.grille[c].candidats, MAXCANDIDATS, i) != MAXCANDIDATS) {

                supprimerValeur(sudoku.grille[c].candidats, MAXCANDIDATS, i);
                sudoku.grille[c].n_candidats--;
            }
        }





        //Colonne
        //Valeurs de la colonne => tcolonne
        j = 0;
        for (int i = valColonne(c); i <= valColonne(c) + (8 * MAXCANDIDATS); i = i + 9) {
            tcolonne[j] = sudoku.grille[i].val;
            j++;

        }

        //Suppression des candidats si une valeur correspondante est déja placée dans la colonne
        for (int i = 1; i <= MAXCANDIDATS; i++) {
            if (rechercheValeur(tcolonne, MAXCANDIDATS, i) != MAXCANDIDATS &&
                rechercheValeur(sudoku.grille[c].candidats, MAXCANDIDATS, i) != MAXCANDIDATS) {
                supprimerValeur(sudoku.grille[c].candidats, MAXCANDIDATS, i);
                sudoku.grille[c].n_candidats--;
            }
        }




        //Region
        //Valeurs de la region => tregion
        j = 0;
        //Indice de la premiere case de la region

        for (int i = indcase; i < indcase + 3; i++) {
            tregion[j] = sudoku.grille[i].val;
            j++;
        }
        for (int i = indcase + 9; i < indcase + 12; i++) {
            tregion[j] = sudoku.grille[i].val;
            j++;
        }
        for (int i = indcase + 18; i < indcase + 21; i++) {
            tregion[j] = sudoku.grille[i].val;
            j++;
        }


        //Suppression des candidats si une valeur correspondante est déja placée dans la colonne
        for (int i = 1; i <= MAXCANDIDATS; i++) {
            if (rechercheValeur(tregion, MAXCANDIDATS, i) != MAXCANDIDATS &&
                rechercheValeur(sudoku.grille[c].candidats, MAXCANDIDATS, i) != MAXCANDIDATS) {
                supprimerValeur(sudoku.grille[c].candidats, MAXCANDIDATS, i);
                sudoku.grille[c].n_candidats--;
            }
        }
    }

}


//Si un candidat n'apparait que pour la case c de la ligne, alors on affecte ce candidat à la case
void R3Ligne(int c, int *clicker) {
    int tcandidats[8*MAXCANDIDATS];//Candidats de la ligne
    int candidatsCaseC[MAXCANDIDATS];//Candidats de la case c
    int k = 0;
    if (sudoku.grille[c].val == 0) {

        //Candidats de la case c
        for (int j = 0; j < MAXCANDIDATS; j++) {
            candidatsCaseC[k] = sudoku.grille[c].candidats[j];
            k++;
        }
        k = 0;


        //Ligne
        //Affection de tous les candidats de la ligne au tableau tcandidats
        for (int i = 9 * (valLigne(c) + 1) - 9; i < (9 * (valLigne(c) + 1) - 9) + 9; i++) {
            //Ignorer les candidats de la case c
            if (i == c) {
                continue;
            }
            if (sudoku.grille[i].val != 0) {    //Si la case a une valeur alors la seule valeur importante est sa valeur
                for (int j = 0; j < MAXCANDIDATS; j++) {
                    tcandidats[k] = sudoku.grille[i].val;
                    k++;
                }
            } else {  //Si la case n'a pas de valeurs on copie tous les candidats
                for (int j = 0; j < MAXCANDIDATS; j++) {
                    tcandidats[k] = sudoku.grille[i].candidats[j];
                    k++;

                }
            }
        }


        for (int i = 0; i < MAXCANDIDATS; i++) {
            if (candidatsCaseC[i] != 0) {
                if (rechercheValeur(tcandidats, 8 * MAXCANDIDATS, candidatsCaseC[i]) == 8 * MAXCANDIDATS) {
                    //Si la valeur candidatsCaseC[i] n'est candidante dans d'autre case de la ligne,
                    //on l'affecte a la case
                    sudoku.grille[c].val = candidatsCaseC[i];
                    *clicker += 1;
                    //On supprime les candidats
                    for (int j = 0; j < MAXCANDIDATS; ++j) {
                        sudoku.grille[c].candidats[j] = 0;
                    }
                    sudoku.grille[c].n_candidats=0;
                    break;
                }
            }

        }


    }

}

//Si un candidat n'apparait que pour la case c de la colonne, alors on affecte ce candidat à la case
void R3Colonne(int c, int *clicker) {

    int tcandidats[8 * MAXCANDIDATS];
    int candidatsCaseC[MAXCANDIDATS];
    int k = 0;
    if (sudoku.grille[c].val == 0) {
        //Candidats de la case c
        for (int j = 0; j < MAXCANDIDATS; j++) {

            candidatsCaseC[k] = sudoku.grille[c].candidats[j];
            k++;
        }
        k = 0;

        //Colonne
        for (int i = valColonne(c); i <= valColonne(c) + (8 * MAXCANDIDATS); i = i + 9) {
            if (i == c) {
                continue;
            }
            //Dans le cas ou la valeur de la case est != 0 alors on affecte 9 fois la valeur de cette case.
            if (sudoku.grille[i].val != 0) {
                for (int j = 0; j < MAXCANDIDATS; j++) {
                    tcandidats[k] = sudoku.grille[i].val;
                    k++;
                }
            } else {

                for (int j = 0; j < MAXCANDIDATS; j++) {
                    tcandidats[k] = sudoku.grille[i].candidats[j];
                    k++;

                }
            }

        }

        for (int i = 0; i < MAXCANDIDATS; i++) {
            if (candidatsCaseC[i] != 0) {
                if (rechercheValeur(tcandidats, 8 * MAXCANDIDATS, candidatsCaseC[i]) == 8 * MAXCANDIDATS) {
                    //Si la valeur candidatsCaseC[i] n'est candidante dans d'autre case de la colonne,
                    //on l'affecte a la case
                    sudoku.grille[c].val = candidatsCaseC[i];
                    *clicker += 1;
                    //On supprime les candidats
                    for (int j = 0; j < MAXCANDIDATS; j++) {
                        sudoku.grille[c].candidats[j] = 0;
                    }
                    sudoku.grille[c].n_candidats=0;
                    break;
                }
            }

        }

    }

}

//Si un candidat n'apparait que pour la case c de la région, alors on affecte ce candidat à la case
void R3Region(int c, int *clicker) {

    int tcandidats[8 * MAXCANDIDATS]; //Candidats de la région
    int candidatsCaseC[MAXCANDIDATS]; //Candidats de la case c
    //indice de début de la region
    int indcase = indiceCase(coordCaseRegionLigne(valReg(c)), coordCaseRegionColonne(valReg(c)));
    int k = 0;
    if (sudoku.grille[c].val == 0) {
        //Candidats de la case c
        for (int j = 0; j < MAXCANDIDATS; j++) {

            candidatsCaseC[k] = sudoku.grille[c].candidats[j];
            k++;
        }

        k = 0;
        //Région
        //Ligne 1 de la région
        for (int i = indcase; i < indcase + 3; i++) {
            if (i == c) {
                continue;
            }

            if (sudoku.grille[i].val != 0) {
                for (int j = 0; j < MAXCANDIDATS; j++) {
                    tcandidats[k] = sudoku.grille[i].val;
                    k++;
                }
            } else {

                for (int j = 0; j < MAXCANDIDATS; j++) {
                    tcandidats[k] = sudoku.grille[i].candidats[j];
                    k++;
                }
            }
        }
        //Ligne 2 de la région
        for (int i = indcase + 9; i < indcase + 12; i++) {
            if (i == c) {
                continue;
            }

            if (sudoku.grille[i].val != 0) {
                for (int j = 0; j < MAXCANDIDATS; j++) {
                    tcandidats[k] = sudoku.grille[i].val;
                    k++;
                }
            } else {

                for (int j = 0; j < MAXCANDIDATS; j++) {
                    tcandidats[k] = sudoku.grille[i].candidats[j];
                    k++;

                }
            }
        }
        //Ligne 3 de la région
        for (int i = indcase + 18; i < indcase + 21; i++) {
            if (i == c) {
                continue;
            }

            if (sudoku.grille[i].val != 0) {
                for (int j = 0; j < MAXCANDIDATS; j++) {
                    tcandidats[k] = sudoku.grille[i].val;
                    k++;
                }
            } else {

                for (int j = 0; j < MAXCANDIDATS; j++) {
                    tcandidats[k] = sudoku.grille[i].candidats[j];
                    k++;

                }
            }
        }


        for (int i = 0; i < MAXCANDIDATS; i++) {
            if (candidatsCaseC[i] != 0) {
                if (rechercheValeur(tcandidats, 8 * MAXCANDIDATS, candidatsCaseC[i]) == 8 * MAXCANDIDATS) {
                    //Si la valeur candidatsCaseC[i] n'est pas candidate dans d'autre case de la région,
                    //on l'affecte a la case
                    sudoku.grille[c].val = candidatsCaseC[i];
                    *clicker += 1;
                    //On supprime les candidats
                    for (int j = 0; j < MAXCANDIDATS; j++) {

                        sudoku.grille[c].candidats[j] = 0;
                    }
                    sudoku.grille[c].n_candidats=0;
                    break;

                }
            }

        }

    }

}


void R4Ligne(int r) {
    int k = 0;
    int tLigne1Region[MAXCANDIDATS * 3];
    int tLigne2Region[MAXCANDIDATS * 3];
    int tLigne3Region[MAXCANDIDATS * 3];
    int candidats[MAXCANDIDATS] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int indcase = 9 * (valLigne(indiceCase(coordCaseRegionLigne(r), coordCaseRegionColonne(r))) + 1) - 9;
    int indcaseR = indiceCase(coordCaseRegionLigne(r), coordCaseRegionColonne(r));

    //Candidats de la région r

    for (int i = indcaseR; i < indcaseR + 3; i++) {
        for (int j = 0; j < MAXCANDIDATS; j++) {
            tLigne1Region[k] = sudoku.grille[i].candidats[j];
            k++;
        }
    }
    k = 0;
    for (int i = indcaseR + 9; i < indcaseR + 12; i++) {
        for (int j = 0; j < MAXCANDIDATS; j++) {
            tLigne2Region[k] = sudoku.grille[i].candidats[j];
            k++;
        }
    }
    k = 0;
    for (int i = indcaseR + 18; i < indcaseR + 21; i++) {
        for (int j = 0; j < MAXCANDIDATS; j++) {
            tLigne3Region[k] = sudoku.grille[i].candidats[j];
            k++;
        }
    }

    //ligne 1
    for (int i = 0; i < MAXCANDIDATS; ++i) {

        if (rechercheValeur(tLigne1Region, MAXCANDIDATS * 3, candidats[i]) != MAXCANDIDATS * 3 &&
            rechercheValeur(tLigne2Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3 &&
            rechercheValeur(tLigne3Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3) {

            for (int l = indcase; l < indcase + 9; l++) {

                if (l == indcaseR && l == indcase) {
                    l = l + 3;
                }

                for (int j = 0; j < MAXCANDIDATS; j++) {
                    if (sudoku.grille[l].candidats[j] == candidats[i]) {
                        sudoku.grille[l].candidats[j] = 0;
                    }
                }

                if (l == indcaseR - 1) {
                    l = l + 3;
                }
            }
        }
    }

    //ligne 2

    for (int i = 0; i < MAXCANDIDATS; ++i) {
        if (rechercheValeur(tLigne1Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3 &&
            rechercheValeur(tLigne2Region, MAXCANDIDATS * 3, candidats[i]) != MAXCANDIDATS * 3 &&
            rechercheValeur(tLigne3Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3) {

            for (int l = indcase + 9; l < indcase + 18; l++) {
                if (l == indcaseR + 9 && l == indcase + 9) {
                    l = l + 3;
                }
                for (int j = 0; j < MAXCANDIDATS; ++j) {
                    if (sudoku.grille[l].candidats[j] == candidats[i]) {
                        sudoku.grille[l].candidats[j] = 0;
                    }
                }

                if (l == indcaseR - 1) {
                    l = l + 3;
                }
            }
        }
    }

    //Ligne 3

    for (int i = 0; i < MAXCANDIDATS; ++i) {
        if (rechercheValeur(tLigne1Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3 &&
            rechercheValeur(tLigne2Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3 &&
            rechercheValeur(tLigne3Region, MAXCANDIDATS * 3, candidats[i]) != MAXCANDIDATS * 3) {

            for (int l = indcase + 18; l < indcase + 27; l++) {
                if (l == indcaseR + 18 && l == indcase + 18) {
                    l = l + 3;
                }

                for (int j = 0; j < MAXCANDIDATS; ++j) {
                    if (sudoku.grille[l].candidats[j] == candidats[i]) {
                        sudoku.grille[l].candidats[j] = 0;
                    }
                }


                if (l == indcaseR - 1) {
                    l = l + 3;
                }
            }
        }
    }


}

//Cette partie est en commentaire car incomplète et corrompt la grille de sudoku
/*void R4Colonne(int r) {
    int k = 0;
    int tColonne1Region[MAXCANDIDATS * 3];
    int tColonne2Region[MAXCANDIDATS * 3];
    int tColonne3Region[MAXCANDIDATS * 3];
    int candidats[MAXCANDIDATS] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int indcase = (valColonne(indiceCase(coordCaseRegionLigne(r), coordCaseRegionColonne(r))) + 1) - 1;
    int indcaseR = indiceCase(coordCaseRegionLigne(r), coordCaseRegionColonne(r));
    //Candidats de la région r

    for (int i = indcaseR; i < indcaseR + 18; i = i + 9) {
        for (int j = 0; j < MAXCANDIDATS; j++) {
            tColonne1Region[k] = sudoku.grille[i].candidats[j];
            k++;
        }
    }
    k = 0;
    for (int i = indcaseR + 1; i < indcaseR + 19; i = i + 9) {
        for (int j = 0; j < MAXCANDIDATS; j++) {
            tColonne2Region[k] = sudoku.grille[i].candidats[j];
            k++;
        }
    }
    k = 0;
    for (int i = indcaseR + 2; i < indcaseR + 20; i = i + 9) {
        for (int j = 0; j < MAXCANDIDATS; j++) {
            tColonne3Region[k] = sudoku.grille[i].candidats[j];
            k++;
        }
    }

    //Colonne 1
    for (int i = 0; i < MAXCANDIDATS; ++i) {

        if (rechercheValeur(tColonne1Region, MAXCANDIDATS * 3, candidats[i]) != MAXCANDIDATS * 3 &&
            rechercheValeur(tColonne2Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3 &&
            rechercheValeur(tColonne3Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3) {

            for (int l = indcase; l < MAXGRILLE; l = l + 9) {

                if (l == indcaseR && l == indcase) {
                    l = l + 27;
                }

                for (int j = 0; j < MAXCANDIDATS; j++) {
                    if (sudoku.grille[l].candidats[j] == candidats[i]) {
                        sudoku.grille[l].candidats[j] = 0;
                    }
                }

                if (l == indcaseR - 9) {
                    l = l + 36;
                }
            }
        }
    }

    //Colonne 2

    for (int i = 0; i < MAXCANDIDATS; i++) {
        if (rechercheValeur(tColonne1Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3 &&
            rechercheValeur(tColonne2Region, MAXCANDIDATS * 3, candidats[i]) != MAXCANDIDATS * 3 &&
            rechercheValeur(tColonne1Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3) {

            for (int l = indcase + 1; l < 81; l = l + 9) {
                if (l == indcaseR + 1 && l == indcase + 1) {
                    l = l + 27;
                }
                for (int j = 0; j < MAXCANDIDATS; ++j) {
                    if (sudoku.grille[l].candidats[j] == candidats[i]) {
                        sudoku.grille[l].candidats[j] = 0;
                    }
                }
                if (l == indcaseR - 1) {
                    l = l + 36;
                }
            }
        }
    }

    //Colonne 3

    for (int i = 0; i < MAXCANDIDATS; ++i) {
        if (rechercheValeur(tColonne1Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3 &&
            rechercheValeur(tColonne2Region, MAXCANDIDATS * 3, candidats[i]) == MAXCANDIDATS * 3 &&
            rechercheValeur(tColonne3Region, MAXCANDIDATS * 3, candidats[i]) != MAXCANDIDATS * 3) {

            for (int l = indcase + 2; l < MAXGRILLE; l = l + 9) {
                if (l == indcaseR + 2 && l == indcase + 2) {
                    l = l + 27;
                }

                for (int j = 0; j < MAXCANDIDATS; ++j) {
                    if (sudoku.grille[l].candidats[j] == candidats[i]) {
                        sudoku.grille[l].candidats[j] = 0;
                    }
                }


                if (l == indcaseR - 1) {
                    l = l + 36;
                }
            }
        }
    }


}*/
