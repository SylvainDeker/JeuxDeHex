/*!
   \file Coordonnee.h
   \brief Coordonnee x y
   \author Sylvain DEKER
   \date 30/04/2017
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
   \brief Coordonnee
   \param Coordonnee
   \param link
        _____________
        |___|_0_|_1_|
          |_5_|_C_|_2_|
            |_4_|_3_|___|

   \return "Return of the function"
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



#endif
