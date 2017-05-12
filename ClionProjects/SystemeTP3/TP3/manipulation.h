//
// Created by salimcherifi on 20/02/17.
//

#ifndef SYSTEMETP3_MANIPULATION_H
#define SYSTEMETP3_MANIPULATION_H

#endif //SYSTEMETP3_MANIPULATION_H

#define LONG_MAX_NOM 20
#define ERREUR_OPEN 1
#define ERREUR_WRITE 2


typedef struct {
    char NOM[LONG_MAX_NOM+1];
    int Age;
    int NbEnfants;
}Infos;

int Creation(char NomFichier[]);
int Consultation(char NomFichier[]);