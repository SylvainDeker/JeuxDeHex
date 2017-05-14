/*!
   \file Liste.c
   \brief Structure de donnée Liste pouvant etre utilisé à la fois mode FILO et FIFO
   \author Sylvain DEKER
   \date 10/04/2017
   \info Liste Simple, doublement chainée avec sentinelle
        Le mode FIFO et FILO se distincte que au moment de la lecture des données soit avec retirer_liste(); soit avec l'itérateur liste_iterateur_courant();
*/

#include "Liste.h"

typedef struct _element{
    void*adr;
    struct _element *next;
    struct _element *prev;
}*Element;

struct _liste{

    Element sentinelle;
    unsigned int taille;

};
/*=================================FONCTIONS LOCALES=================================*/


void connexion(Element prev,Element next){
    prev->next=next;
    next->prev=prev;
}

/*==================================FONCTIONS PUBLIQUE=============================*/
Liste constructeur_liste(void){
    Liste l=(Liste)malloc(sizeof(struct _liste));
    l->sentinelle=(Element)malloc(sizeof(struct _element));
    connexion(l->sentinelle,l->sentinelle);
    l->taille=0;

    return l;
}
unsigned int liste_taille(Liste l){
    return l->taille;
}




Liste liste_fusion(Liste l1,Liste l2){
    assert(l1!=l2);
    while(!liste_vide(l2)){
        ajout_liste(l1,retirer_liste(l2,FIFO));
    }
    // freed_liste(l2);
    return l1;
}


Liste ajout_liste(Liste list,void * adr){
    assert(list);

    Element e=(Element)malloc(sizeof(struct _element));
    e->adr=adr;
    Element tmp=list->sentinelle->next;
    connexion(list->sentinelle,e);
    connexion(e,tmp);
    (list->taille)++;
    return list;
}

bool supprim_element_liste(Liste l,void *element){
    Element prev,next,itr=l->sentinelle->next;
    bool found=false;
    bool unfoundable=false;
    while(!found && !unfoundable){
        if (itr==l->sentinelle)unfoundable=true;
        else if(itr->adr==element)found=true;
        else itr =itr->next;
    }
    if(found){
        prev=itr->prev;
        next=itr->next;
        connexion(prev,next);
        free(itr);
        l->taille--;
    }
    return found;
}


void freed_liste(Liste list){
    assert(list);
    Element next,itr=list->sentinelle->next;
    while (itr!=list->sentinelle) {

        next=itr->next;
        free(itr);
        itr=next;
    }
    free(list->sentinelle);
    free(list);
}


bool liste_vide(Liste list){
    return list->taille ==0;
}

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


struct _list_itr{
    Liste l;
    Element courant;
    char methode;
};

ListeItr constructeur_liste_iterateur(Liste l,const char methode){
    ListeItr new=(ListeItr)malloc(sizeof(struct _list_itr));
    new->l=l;
    new->methode=methode;

    return new;
}


void*liste_iterateur_courant(ListeItr i){
    return i->courant->adr;
}

ListeItr start_liste_iterateur(ListeItr i){
    if(i->methode =='l')//fifo
        i->courant=i->l->sentinelle->next;
    if(i->methode == 'f')//fifo
        i->courant=i->l->sentinelle->prev;
    return i;
}

ListeItr suivant_liste_iterateur(ListeItr i){
    if(i->methode =='l')//fifo
        i->courant=i->courant->next;
    if(i->methode =='f')//fifo
        i->courant=i->courant->prev;
    return i;
}

bool fin_liste_iterateur(ListeItr i){
    return i->courant==i->l->sentinelle;
}

void freed_liste_iterateur(ListeItr i){
    free(i);
}
