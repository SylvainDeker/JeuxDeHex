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
typedef struct _coordonnee{
    int x;
    int y;
}Coordonnee;

Coordonnee Coord(int x, int y);


#endif
