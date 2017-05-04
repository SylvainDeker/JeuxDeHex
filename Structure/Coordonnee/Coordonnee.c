/*!
   \file Coordonnee.h
   \brief Coordonnee x y
   \author Sylvain DEKER
   \date 30/04/2017
*/
#define _POSIX_C_SOURCE 1

#include "Coordonnee.h"

Coordonnee Coord(int x, int y){
    assert(x>=0&&y>=0);
    Coordonnee new;
    new.x=x;
    new.y=y;
    return new;
}
