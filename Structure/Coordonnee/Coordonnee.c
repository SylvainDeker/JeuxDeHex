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


Coordonnee Coord_voisin(Coordonnee c,int link){
    assert(link<6);
    assert(link>=0);
    Coordonnee voisin;

    switch (link) {
        case 0:
            voisin.x=c.x-1;
            voisin.y=c.y;
            break;
        case 1:
            voisin.x=c.x-1;
            voisin.y=c.y+1;
            break;
        case 2:
            voisin.x=c.x;
            voisin.y=c.y+1;
            break;
        case 3:
            voisin.x=c.x+1;
            voisin.y=c.y;
            break;
        case 4:
            voisin.x=c.x+1;
            voisin.y=c.y-1;
            break;
        case 5:
            voisin.x=c.x;
            voisin.y=c.y-1;
            break;
    }
    return voisin;
}


bool Coord_valide(Coordonnee c,unsigned int min,unsigned int max){
    return c.x>=min && c.x<max&&c.y>=min && c.y<max;
}
