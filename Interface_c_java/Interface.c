/*!
   \file Undo.c
   \brief Undo.c
   \author Sylvain DEKER
   \date 13/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Interface.h"

void lecture_flux(FILE*pipeline){

    int c;
    while((c=getc(pipeline))!='\n'){
        printf("%c",(char)c );
    }
    // for (size_t i = 0; i < 10; i++) {
    //     printf("%c",getc(pipeline) );
    // }

}


int envoyer_data(Plateau p){
    FILE*c_vers_java=fopen("c_vers_java","w");
    if(c_vers_java){
        fprintf(c_vers_java, "%u,",Dimention_plateau(p) );
        for (unsigned int i = 0; i < Dimention_plateau(p); i++) {
            for (unsigned int j = 0; j < Dimention_plateau(p); j++) {
                if(Groupe_de_la_Case(Case_de_la_Coordonnee(p, Coord(i,j)) )){
                    if(Joueur1(p)==Joueur_du_groupe(Groupe_de_la_Case(Case_de_la_Coordonnee(p,Coord(i,j)) )))
                        fprintf(c_vers_java, "1," );
                    else
                        fprintf(c_vers_java, "2," );
                }
                else
                    fprintf(c_vers_java, "0," );

            }
        }

    }
    else return -1;




    return 0;
}
