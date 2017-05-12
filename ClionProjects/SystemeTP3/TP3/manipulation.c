
#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <stdlib.h>
#include "manipulation.h"

int Creation(char NomFichier[]){
    int fich;
    fich=open(NomFichier,O_RDWR|O_CREAT,S_IRWXU);
    if (fich==-1){
        perror("open file");
        return ERREUR_OPEN;
    }
    Infos I;
    int nb;
    printf("-----Combien de personnes voulez-vous entrer ?-----\n");
    scanf("%d",&nb);

    for (int i = 0; i < nb; ++i) {
        printf("-----Nom : ");
        scanf("%s",I.NOM);
        printf("-----Age : ");
        scanf("%d",&I.Age);
        printf("-----Nombre d'enfants : ");
        scanf("%d",&I.NbEnfants);
        if(write(fich,&I, sizeof(I)) != sizeof(I)){
            perror("write");
            close(fich);
            return ERREUR_WRITE;

        }
    }
    close(fich);

    return 0;

}


int Consultation(char NomFichier[]){
    int fich;


    int numFiche = 0;
    Infos fiche;
    fich=open(NomFichier,O_RDWR);
    if (fich==-1){
        perror("open file");
        return ERREUR_OPEN;
    }
    int nbFiches = lseek(fich,0,SEEK_END)/sizeof(Infos);
    if(nbFiches == -1)

    printf("-----Nombre de fiches dans le fichier : %d-----\n",nbFiches);
    printf("-----Quel est le numéro de la fiche que vous voulez consulter ?-----\n");
    scanf("%d",&numFiche);
    printf("\n\n\n\n");
    lseek(fich,(nbFiches-1)*sizeof(fiche),SEEK_SET);
    read(fich,&fiche, sizeof(fiche));


    printf("-----Nom : %s-----\n",fiche.NOM);
    printf("-----Age : %d-----\n",fiche.Age);
    printf("-----Nombre d'enfants : %d-----\n\n",fiche.NbEnfants);


    close(fich);
    return 0;


}

