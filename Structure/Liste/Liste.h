/*!
   \file Liste.h
   \brief Structure de donnée Liste pouvant etre utilisé à la fois mode FILO et FIFO
   \author Sylvain DEKER
   \date 10/04/2017
   \info Liste Simple, doublement chainée avec sentinelle
        Le mode FIFO et FILO se distincte que au moment de la lecture des données soit avec retirer_liste(); soit avec l'itérateur liste_iterateur_courant();
*/

#ifndef  _LISTE_H_
#define _LISTE_H_

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define FIFO 'f'
#define FILO 'l'


typedef struct _liste*Liste;//La liste
typedef struct _list_itr*ListeItr;//Iterateur de la liste

/*!
   \brief Constructeur da la liste
   \return Liste
   \Warn Memoire doit etre libérée par la fonction freed_liste()
*/
Liste constructeur_liste(void);

/*!
   \brief Retirer un element
   \param Liste
   \param methode de retrait FIFO ou FILO
   \pre taille > 0
   \return adresse de l'element un cast est nécéssaire !
*/
void*retirer_liste(Liste list,const char methode);


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

/*!
   \brief Permet de supprimer un element designé
   \param Liste l
   \param poiteur sur l'element;
   \post taille -1 si element trouvé
   \return bool 1 si l'element est trouvé (et donc est supprimé), 0 sinon
*/
bool supprim_element_liste(Liste l,void *element);

/*!
   \brief Constructure de la structure de donnée Itérateur de la liste Liste selon la méthode choisie
   \param Liste l
   \param Choix de la methode FIFO ou FILO
   \return poiteur vers la structure de donnée
*/
ListeItr constructeur_liste_iterateur(Liste l,const char methode);

/*!
   \brief Permet d'initaliser l'iterateur selon sa methode
   \param Iterateur i
   \return Retourne l'adresse de l'érateur
*/
ListeItr start_liste_iterateur(ListeItr i);

/*!
   \brief Permet de revoyer l'adresse du composant enregistré à la l'element courant
   \param Iterateur
   \return l'adresse (void*) vers le composant enregistré
*/
void*liste_iterateur_courant(ListeItr i);

/*!
   \brief Permet d'incrmenter l'Iterateur de la liste
   \param Iterateur
   \return Iterateur
*/
ListeItr suivant_liste_iterateur(ListeItr i);

/*!
   \brief Permet de sovoir si l'itérateur à parcourus tout les elements ou non
   \param Iterateur
   \return bool 1 = Liste entierrement parcourue, 0 sinon
*/
bool fin_liste_iterateur(ListeItr i);

/*!
   \brief Permet de liberer la mémoir prise par l'itérateur
   \param Iterateur
*/
void freed_liste_iterateur(ListeItr i);



#endif
