#define MAXGRILLE 81
#define MAXCANDIDATS 9

typedef struct
{
    int val ; /* Valeur de la case (0 si vide)*/
    int n_candidats ; /* Nombre de candidats possibles */
    int candidats[MAXCANDIDATS] ; /* Liste de candidats */
} T_case ;

typedef struct
{
    T_case grille[MAXGRILLE] ; /*vecteur de 81 cases*/
} T_sudoku ;

//Remplir la grille au clavier
void remplirgrille();
//Initialiser la grille avec celle dans le code
void initialiser();
//Initialiser la grille avec un fichier
void initialiserVal(int *v);
//Afficher la grille
void afficher();
//Renvoi la ligne de la première case de la région
int coordCaseRegionLigne(int r);
//Renvoie la colonne de la première case de la région
int coordCaseRegionColonne(int r);
//Renvoie la colonne de la case
int valColonne(int c);
//Renvoie la ligne de la case
int valLigne(int c);
//Renvoie la région de la case
int valReg(int c);
//Renvoie l'indice de la case en fonction de la ligne et de la colonne
int indiceCase(int l, int c);
//Recherche la valeur v dans le tableau t de taille n
int rechercheValeur(int t[], int n, int v);
//Supprime la valeur v du tableau t de taille n
void supprimerValeur(int t[], int n, int v);

void R1(int c, int *clicker);
void R2(int c);
void R3Ligne(int c, int *clicker);
void R3Colonne(int c, int *clicker);
void R3Region(int c, int *clicker);
void R4Ligne(int r);
//void R4Colonne(int r);

//Permet de mettre a 0 mes candidats des case deja affectées
void cleanup();