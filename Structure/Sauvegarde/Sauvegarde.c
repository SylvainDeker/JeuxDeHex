/*!
   \file Sauvegarde.c
   \brief Sauvegarde.c
   \author Sylvain DEKER
   \date 11/05/2017
*/

#define _POSIX_C_SOURCE 1
#include "Sauvegarde.h"



bool sauvegarder_partie(Plateau p,const char*nom_fichier,const char*description){
    unsigned int dim=Dimention_plateau(p);
    FILE*fichier_sauvegarde=fopen(nom_fichier,"w");
    if(fichier_sauvegarde){
        /*
        \hex
        \dim 5
        \board Mon premier test
        */
        fprintf(fichier_sauvegarde, "\\hex\n\\dim %u\n\\board %s\n",dim,description);
        /*
        W W W/B
        B * * o B
          B * * o B
            B o o o B
              B/W W W

        */
        for (unsigned int i = 0; i < dim-1; i++){
            fprintf(fichier_sauvegarde, "W ");
        }
        fprintf(fichier_sauvegarde, "W/B\n");
        for (unsigned int i = 0; i < dim; i++){
            for (unsigned int j = 0; j < i; j++){
                fprintf(fichier_sauvegarde,"  ");
            }
            fprintf(fichier_sauvegarde, "B ");
            for ( unsigned int j = 0; j < dim; j++) {
                if(!Case_Vide(p,Coord(i,j))){
                    if(Joueur_du_groupe( Groupe_de_la_Case( Case_de_la_Coordonnee(p,Coord(i,j)) ) )==Joueur1(p))
                        fprintf(fichier_sauvegarde,"* " );
                    else
                        fprintf(fichier_sauvegarde,"o " );
                }
                else fprintf(fichier_sauvegarde,". " );
            }
            fprintf(fichier_sauvegarde, "B\n");
        }
        for (unsigned int j = 0; j < dim; j++){
            fprintf(fichier_sauvegarde,"  ");
        }
        fprintf(fichier_sauvegarde, "B/W ");
        for (unsigned int i = 0; i < dim-1; i++){
            fprintf(fichier_sauvegarde, "W ");
        }
        /*
        \game
        \play * 0 1
        \play o 1 2
        \play * 1 1
        \play o 2 1
        \play * 0 0
        \play o 0 2
        \play * 1 0
        \play o 2 0
        \play o 2 2
        */
        fprintf(fichier_sauvegarde, "\n\\game\n");
        ListeItr itr_historique_joueur1,itr_historique_joueur2;
        itr_historique_joueur1=constructeur_liste_iterateur(Historique_Joueur(Joueur1(p)),FIFO);
        itr_historique_joueur2=constructeur_liste_iterateur(Historique_Joueur(Joueur2(p)),FIFO);

        start_liste_iterateur(itr_historique_joueur1);
        start_liste_iterateur(itr_historique_joueur2);
        Case cas;
        Coordonnee cd;
        //premier if à l'exterieur du for permet d'assuré l'altérnance  o * o * o au lieu de * o * o o ds le fichier sauvé.
        if(!fin_liste_iterateur(itr_historique_joueur1)&& liste_taille(Historique_Joueur(Joueur1(p))) > liste_taille(Historique_Joueur(Joueur2(p))) ){
            cas=(Case)liste_iterateur_courant(itr_historique_joueur2);
            cd=Coordonne_de_la_Case(cas);
            fprintf(fichier_sauvegarde, "\\play o %d %d\n",cd.x,cd.y );
            suivant_liste_iterateur(itr_historique_joueur2);

        }

        while(!fin_liste_iterateur(itr_historique_joueur1) || !fin_liste_iterateur(itr_historique_joueur2) ){



            if(!fin_liste_iterateur(itr_historique_joueur2)){
                cas=(Case)liste_iterateur_courant(itr_historique_joueur2);
                cd=Coordonne_de_la_Case(cas);
                fprintf(fichier_sauvegarde, "\\play o %d %d\n",cd.x,cd.y );
                suivant_liste_iterateur(itr_historique_joueur2);

            }
            if(!fin_liste_iterateur(itr_historique_joueur1)){
                cas=(Case)liste_iterateur_courant(itr_historique_joueur1);
                cd=Coordonne_de_la_Case(cas);
                fprintf(fichier_sauvegarde, "\\play * %d %d\n",cd.x,cd.y );
                suivant_liste_iterateur(itr_historique_joueur1);
            }


        }
        freed_liste_iterateur(itr_historique_joueur1);
        freed_liste_iterateur(itr_historique_joueur2);
        /*
        \endgame
        \endhex
        */

        fprintf(fichier_sauvegarde, "\\endgame\n");
        fprintf(fichier_sauvegarde, "\\endhex\n");

        fclose(fichier_sauvegarde);
    }
    return (bool)fichier_sauvegarde;
}



bool insersion_graphique()




bool restaurer_partie(const char * nom_fichier,Plateau *p){

    Joueur j1=contructeur_Joueur();
    Joueur j2=contructeur_Joueur();

    unsigned int dim;

    FILE*fichier_sauvegarde=fopen(nom_fichier,"r");
    if(fichier_sauvegarde){
        // Recuperation de la dimention
        fscanf(fichier_sauvegarde, "\\hex\n\\dim %u\n",&dim);
        *p=constructeur_plateau(dim,j1,j2);
        //pour passé la descrition de longueur variable
        while(fgetc(fichier_sauvegarde)!='\n');
        //Pour passé la représentation graphique
        fseek(fichier_sauvegarde, (dim-1)*2+4, SEEK_CUR);
        for (unsigned int i = 0; i < dim; i++){
            for (unsigned int j = 0; j < i; j++){
                fseek(fichier_sauvegarde,2, SEEK_CUR);
            }
            fseek(fichier_sauvegarde,2, SEEK_CUR);
            for ( unsigned int j = 0; j < dim; j++) {
                fseek(fichier_sauvegarde,2, SEEK_CUR);
            }
            fseek(fichier_sauvegarde,2, SEEK_CUR);
        }
        while(fgetc(fichier_sauvegarde)!='\n');
        fscanf(fichier_sauvegarde,"\\game\n");
        char joueur;

        int x;
        int y;
        //Restructuration du jeu
            while(fscanf(fichier_sauvegarde,"\\play %c %d %d\n",&joueur,&x,&y)){
                if(joueur=='*') poser_un_pion(*p,j1,Coord(x,y));
                else poser_un_pion(*p,j2,Coord(x,y));
            }
        fclose(fichier_sauvegarde);
    }
    return (bool)fichier_sauvegarde;










}
