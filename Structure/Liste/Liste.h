/*!
   \file Liste.h
   \brief Module Liste
   \author Sylvain DEKER
   \date 10/04/2017
*/

#ifndef  _LISTE_H_
#define _LISTE_H_

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef struct _liste*Liste;
typedef struct _list_itr*ListeItr;

/*!
   \brief Constructeur da la liste
   \return Liste
*/
Liste constructeur_liste(void);

/*!
   \brief Retirer un element
   \param Liste
   \param methode de retrait "liste" ou "pile"
   \pre taille > 0
   \return adresse de l'element un cast est nécéssaire !
*/
void*retirer_liste(Liste list,const char*methode);


/*!
   \brief Ajouter la liste
   \param liste
   \param adresse de l'elementa ajouter
   \post taille>0
   \return Liste
*/

Liste ajout_liste(Liste list,void * adr);
/*!
   \brief libération de la mémoire
   \param Liste
*/
void freed_liste(Liste list);

/*!
   \brief Determine si la liste est vide ou non
   \param Liste
   \return bool 1=vide , 0 = au moins un element
*/
bool liste_vide(Liste list);

/*!
   \brief Retourne le nombre d'element dans la liste
   \param Liste
   \return Retourne le nombre d'element dans la liste
*/
unsigned int liste_taille(Liste l);

/*!
   \brief Permet de fusionner deux liste
   \param Liste 1
   \param Liste 2
   \post Liste2 est copié L1 puis supprimé
   \return "Return of the function"
*/
Liste liste_fusion(Liste l1,Liste l2);




ListeItr constructeur_liste_iterateur(Liste l);
void*liste_iterateur_courant(ListeItr i);
ListeItr start_liste_iterateur(ListeItr i);
ListeItr suivant_liste_iterateur(ListeItr i);
bool fin_liste_iterateur(ListeItr i);
void freed_liste_iterateur(ListeItr i);
bool supprim_element_liste(Liste l,void *element);


#endif
