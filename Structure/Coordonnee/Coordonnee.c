/*!
   \file Coordonnee.c
   \brief Structure de donnée Statique permettant de faire transiter des Coordonnee x et y.
   \author Sylvain DEKER
   \date 30/04/2017
   \info Implementation Statique choisie pour deux raisons:
        - L'espace occupé par une "instance" Coordonnee est toujours la même (deux elements x et y).
        - Pour ne pas alloourdire le code des fonctions de niveau suppérieur avec des constructeurs et des libérateurs.
*/
#define _POSIX_C_SOURCE 1

#include "Coordonnee.h"

/*!
   \brief Construction du Coordonnee a partir de x et y
   \param x
   \param y
   \return Coordonnee
*/
Coordonnee Coord(int x, int y){
    assert(x>=0&&y>=0);//Les Coordonnee sur notre plateau de jeux sont toujours positifs ou nulles
    Coordonnee new;
    new.x=x;
    new.y=y;
    return new;
}


/*!
   \brief Fonction permettant trouver les Coordonnee d'un hexagone voisin cad qui lui est "dirrectement connecté" selon la definition donné dans le document technique.
   \param Coordonnee
   \param num_voisin_relatif
   \return "Return of the function"
   \info Chaque hexagone (hors ceux qui se trouvent en bordure) ont 6 voisins, ces 6 voisins sont représenté par un numero:
        - Soit c la Coordonnee de l'hexagonne courant.
        - Soient 0,1,2,3,4 et 5 les differents voisins autour de notre hexagonne courant.
        - Les effets de bords devront etre gerer par la suite ( si la Coordonnee courante est c=(x=0,y=0) alors son voisin n°0 est v=(x=-1,y=0) qui n'existe pas ).
            Pour ce dernier point on peut utiliser la fonction Coord_valide();
   _____________
   |___|_0_|_1_|
     |_5_|_C_|_2_|
       |_4_|_3_|___|


*/

Coordonnee Coord_voisin(Coordonnee c,int num_voisin_relatif){
    /*Il  existe 6 voisins maximun numeroté de 0 à 5*/
    assert(num_voisin_relatif<6);
    assert(num_voisin_relatif>=0);
    Coordonnee voisin;

    switch (num_voisin_relatif) {
        case 0:
            /*Voisin n°0*/
            voisin.x=c.x-1;
            voisin.y=c.y;
            break;
        case 1:
            /*Voisin n°1*/
            voisin.x=c.x-1;
            voisin.y=c.y+1;
            break;
        case 2:
            /*Voisin n°2*/
            voisin.x=c.x;
            voisin.y=c.y+1;
            break;
        case 3:
            /*Voisin n°3*/
            voisin.x=c.x+1;
            voisin.y=c.y;
            break;
        case 4:
            /*Voisin n°4*/
            voisin.x=c.x+1;
            voisin.y=c.y-1;
            break;
        case 5:
            /*Voisin n°5*/
            voisin.x=c.x;
            voisin.y=c.y-1;
            break;
    }
    return voisin;
}

/*!
   \brief Determine si des Coordonnee sont valide cad si les
        Coordonnee x et y sont bien dans l'intervale [min;max[ (max exclu !)
   \param Coordonnee
   \param min
   \param max
   \return true si valide false sinon
*/
bool Coord_valide(Coordonnee c,unsigned int min,unsigned int max){
    return c.x>=min && c.x<max&&c.y>=min && c.y<max;
}
