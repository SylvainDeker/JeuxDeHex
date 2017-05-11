/*!
   \file Coordonnee.h
   \brief Coordonnee x y
   \author Sylvain DEKER
   \date 30/04/2017
*/
#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include "Coordonnee.h"

int main(int argc, char const *argv[]) {

    Coordonnee c=Coord(2,3);
    printf("%d,%d\n",c.x,c.y );
    printf("%d\n",Coord(7,8).x );


    return 0;
}
