/*!
   \file Undo.c
   \brief Undo.c
   \author Sylvain DEKER
   \date 13/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Interface.h"










int lecture_requete(char * ordre){
    int c;
    FILE*c_vers_java=fopen("java_vers_c","r");
    if(c_vers_java){
        int i=0;
        while((c=getc(c_vers_java))!='\n'){
            ordre[i++]=(char)c;
        }
        ordre[i]='\0';
        fclose(c_vers_java);
    }
    else return -1;
return 0;

}


int envoyer_grille(Plateau p){
    FILE*c_vers_java=fopen("c_vers_java","w");
    if(c_vers_java){
        fprintf(c_vers_java, "%u-",Dimention_plateau(p) );
        for (unsigned int i = 0; i < Dimention_plateau(p); i++) {
            for (unsigned int j = 0; j < Dimention_plateau(p); j++) {
                if(Groupe_de_la_Case(Case_de_la_Coordonnee(p, Coord(i,j)) )){
                    if(Joueur1(p)==Joueur_du_groupe(Groupe_de_la_Case(Case_de_la_Coordonnee(p,Coord(i,j)) )))
                        fprintf(c_vers_java, "1" );
                    else
                        fprintf(c_vers_java, "2" );
                }
                else
                    fprintf(c_vers_java, "0" );

            }
        }
        fprintf(c_vers_java, "\n" );
        fclose(c_vers_java);
    }
    else return -1;

    return 0;
}

int envoyer_existe_gagnant(Plateau p){
    FILE*c_vers_java=fopen("c_vers_java","w");
    if(c_vers_java){
        if(Existe_Gangnant(p)==Joueur1(p)) fprintf(c_vers_java, "1" );
        if(Existe_Gangnant(p)==Joueur2(p)) fprintf(c_vers_java, "2" );
        if(Existe_Gangnant(p)==NULL)fprintf(c_vers_java, "0");
        fprintf(c_vers_java, "\n" );
        fclose(c_vers_java);
    }
    else return -1;

    return 0;

}
