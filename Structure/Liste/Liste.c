/*!
   \file Liste.c
   \brief Structure de donnée Liste pouvant etre utilisé à la fois mode FILO et FIFO
   \author Sylvain DEKER
   \date 10/04/2017
   \info Liste Simple, doublement chainée avec sentinelle
        Le mode FIFO et FILO se distincte que au moment de la lecture des données soit avec retirer_liste(); soit avec l'itérateur liste_iterateur_courant();
*/

#include "Liste.h"

//Element de la liste
typedef struct _element{
    void*adr;
    struct _element *next;
    struct _element *prev;
}*Element;

//Liste
struct _liste{

    Element sentinelle;
    unsigned int taille;

};

//iterateur de la liste
struct _list_itr{
    Liste l;
    Element courant;
    char methode;
};

/*=================================FONCTIONS LOCALES=================================*/

/*!
   \brief Permet de connecter deux element qui se suivent parmis les elements de la liste²²
   \param Element prev
   \param Element next
*/
void connexion(Element prev,Element next){
    prev->next=next;
    next->prev=prev;
}

/*==================================FONCTIONS PUBLIQUE=============================*/
/*!
   \brief Constructeur da la liste
   \return Liste
   \Warn Memoire doit etre libérée par la fonction freed_liste()
*/
Liste constructeur_liste(void){
    Liste l=(Liste)malloc(sizeof(struct _liste));
    l->sentinelle=(Element)malloc(sizeof(struct _element));
    connexion(l->sentinelle,l->sentinelle);
    l->taille=0;

    return l;
}

/*!
   \brief Retourne le nombre d'element dans la liste
   \param Liste
   \return Retourne le nombre d'element dans la liste
*/
unsigned int liste_taille(Liste l){
    return l->taille;
}


/*!
   \brief Permet de fusionner deux liste
   \param Liste 1
   \param Liste 2
   \post Liste2 est copié L1 puis supprimé
   \return "Return of the function"
*/
Liste liste_fusion(Liste l1,Liste l2){
    assert(l1!=l2);
    while(!liste_vide(l2)){
        ajout_liste(l1,retirer_liste(l2,FIFO));//Vide l2 et rempli l1 en meme temps
    }
    // freed_liste(l2);
    return l1;
}

/*!
   \brief Ajouter la liste
   \param liste
   \param adresse de l'elementa ajouter
   \post taille>0
   \return Liste
*/
Liste ajout_liste(Liste list,void * adr){
    assert(list);
    //Construction de l'élément
    Element e=(Element)malloc(sizeof(struct _element));
    e->adr=adr;
    //Connexion avec le reste des elements de la liste
    Element tmp=list->sentinelle->next;
    connexion(list->sentinelle,e);
    connexion(e,tmp);
    //Incrementation de la taille
    (list->taille)++;
    return list;
}

/*!
   \brief Permet de supprimer un element designé
   \param Liste l
   \param poiteur sur l'element;
   \post taille -1 si element trouvé
   \return bool 1 si l'element est trouvé (et donc est supprimé), 0 sinon
*/
bool supprim_element_liste(Liste l,void *element){
    Element prev,next,itr=l->sentinelle->next;
    bool found=false;
    bool unfoundable=false;
    //Recherche de l'element à supprimer
    while(!found && !unfoundable){
        if (itr==l->sentinelle)unfoundable=true;
        else if(itr->adr==element)found=true;
        else itr =itr->next;
    }
    //Si l'element recherché existe :
    if(found){
        prev=itr->prev;
        next=itr->next;
        connexion(prev,next);
        free(itr);
        l->taille--;
    }
    return found;
}

/*!
   \brief libération de la mémoire
   \param Liste
*/
void freed_liste(Liste list){
    assert(list);
    Element next,itr=list->sentinelle->next;
    //Libere tout les elements
    while (itr!=list->sentinelle) {

        next=itr->next;
        free(itr);
        itr=next;
    }
    //libere la sentinelle
    free(list->sentinelle);
    //Libere la structure liste elle-même
    free(list);
}

/*!
   \brief Determine si la liste est vide ou non
   \param Liste
   \return bool 1=vide , 0 = au moins un element
*/
bool liste_vide(Liste list){
    return list->taille ==0;
}
/*!
   \brief Retirer un element
   \param Liste
   \param methode de retrait FIFO ou FILO
   \pre taille > 0
   \return adresse de l'element un cast est nécéssaire !
*/
void*retirer_liste(Liste list,const char methode){
    assert(list->taille>0);

    void*adr;
    Element del,tmp;

    switch (methode) {
        case 'l'://filo
            del=list->sentinelle->next;
            tmp=del->next;
            adr=del->adr;
            connexion(list->sentinelle,tmp);
            break;
        case 'f'://fifo
            del=list->sentinelle->prev;
            tmp=del->prev;
            adr=del->adr;
            connexion(tmp,list->sentinelle);
            break;
        default:
            assert(0);
    }

    free(del);
    list->taille--;
    return adr;
}

/*
void afficher(Liste l){
    Element i=l->sentinelle->next;
    while(i!=l->sentinelle){
        printf("%d !!!! \n",*((int*)i->adr ));
        i=i->next;
    }


}
*/

////////////////////////////////iterateur

/*!
   \brief Constructure de la structure de donnée Itérateur de la liste Liste selon la méthode choisie
   \param Liste l
   \param Choix de la methode FIFO ou FILO
   \return poiteur vers la structure de donnée
*/
ListeItr constructeur_liste_iterateur(Liste l,const char methode){
    ListeItr new=(ListeItr)malloc(sizeof(struct _list_itr));
    new->l=l;
    new->methode=methode;
    return new;
}

/*!
   \brief Permet de revoyer l'adresse du composant enregistré à la l'element courant
   \param Iterateur
   \return l'adresse (void*) vers le composant enregistré
*/
void*liste_iterateur_courant(ListeItr i){
    return i->courant->adr;
}

/*!
   \brief Permet d'initaliser l'iterateur selon sa methode
   \param Iterateur i
   \return Retourne l'adresse de l'érateur
*/
ListeItr start_liste_iterateur(ListeItr i){
    if(i->methode =='l')//filo
        i->courant=i->l->sentinelle->next;
    if(i->methode == 'f')//fifo
        i->courant=i->l->sentinelle->prev;
    return i;
}

/*!
   \brief Permet d'incrmenter l'Iterateur de la liste
   \param Iterateur
   \return Iterateur
*/
ListeItr suivant_liste_iterateur(ListeItr i){
    if(i->methode =='l')//fifo
        i->courant=i->courant->next;
    if(i->methode =='f')//fifo
        i->courant=i->courant->prev;
    return i;
}

/*!
   \brief "Description"
   \param "Param description"
   \pre "Pre-conditions"
   \post "Post-conditions"
   \return "Return of the function"
*/
bool fin_liste_iterateur(ListeItr i){
    return i->courant==i->l->sentinelle;
}
/*!
   \brief Permet de liberer la mémoir prise par l'itérateur
   \param Iterateur
*/
void freed_liste_iterateur(ListeItr i){
    free(i);
}
