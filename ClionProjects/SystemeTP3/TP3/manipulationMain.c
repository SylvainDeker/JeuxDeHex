

#include <stdio.h>
#include <stdlib.h>
#include "manipulation.h"

int main(){
	char nomFichier;
    int erreur;
    int choix = 0;
	while(choix != 3){
    	printf("Que voulez- vous faire ?\n");
		printf("------ 1- Consulter une fiche dans un fichier ------\n");
		printf("------ 2- Créer un fichier de fiche(s) ------\n");
		printf("------ 3- Sortir ------\n");
		printf("(Veuillez entrer le numéro de votre choix)\n");
		scanf("%d", &choix);
		switch(choix){
			case 1:
	    		printf("-----Quel est le nom du fichier que vous voulez consulter ?-----\n");
	    		scanf("%s",&nomFichier);
	    		erreur = Consultation(&nomFichier);
	    		if (erreur != 0)
	    		{
	    			return erreur;
	    		}
	    		break;
	    	case 2:
	    		printf("-----Quel est le nom du fichier que vous voulez créer ?-----\n");
	    		scanf("%s",&nomFichier);
	    		erreur = Creation(&nomFichier);
	    		if (erreur != 0)
	    		{
	    			return erreur;
	    		}
	    		break;
	    	case 3:
	    		break;
	    	default:
	    		printf("Vous n'avez pas choisis une option valide\n");
		}
    }
	
   
    
    return 0;
}