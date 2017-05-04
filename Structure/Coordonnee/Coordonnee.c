/*!
   \file Coordonnee.h
   \brief Coordonnee x y
   \author Sylvain DEKER
   \date 30/04/2017
*/
#define _POSIX_C_SOURCE 1

#include "Coordonnee.h"

Coordonnee Coord(int x, int y){
    Coordonnee new;
    new.x=x;
    new.y=y;
    return new;
}
