/*!
   \file Coordonnee.h
   \brief Header de la structure de donnée Statique permettant de faire transiter des Coordonnee x et y.
   \author Sylvain DEKER
   \date 30/04/2017
   \info Implementation Statique choisie pour deux raisons:
        - L'espace occupé par une "instance" Coordonnee est toujours la même (deux elements x et y).
        - Pour ne pas alloourdire le code des fonctions de niveau suppérieur avec des constructeurs et des libérateurs.
*/
#define _POSIX_C_SOURCE 1

#ifndef _COORDONNEE_H_
#define _COORDONNEE_H_

    #include <assert.h>
    #include <stdbool.h>

    typedef struct _coordonnee{
        int x;
        int y;
    }Coordonnee;

    /*!
       \brief Construction du Coordonnee a partir de x et y
       \param x
       \param y
       \return Coordonnee
    */
    Coordonnee Coord(int x, int y);

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
    Coordonnee Coord_voisin(Coordonnee c,int link);

    /*!
       \brief Determine si des Coordonnee sont valide cad si les
            Coordonnee xet y sont bien dans l'intervale [min;max[ (max exclu !)
       \param Coordonnee
       \param min
       \param max
       \return true si valide false sinon
    */
    bool Coord_valide(Coordonnee c,unsigned int min,unsigned int max);




    Coordonnee Coord_pont(Coordonnee c,int num_pont_relatif);

#endif
