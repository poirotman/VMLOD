#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste l;
	l = calloc(1, sizeof(Cellule));
	l->val = v;
	l->suiv = NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
		Liste s;
		s = creer(v);
		s->suiv = l ;
		return s;
}


void afficheElement(Element e) {
	printf("%i\n",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	while( l!=NULL){
			afficheElement(l->val);
			l=l->suiv;
	}
	printf("------------------\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if(l!=NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
	else{
		printf("------------------\n");
	}
}

void detruireElement(Element e) {
	
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste tmp=NULL;
	while(l!=NULL){
		tmp = l->suiv;
		detruireElement(l->val);
		free(l);
		l=tmp;	
	}
}

// version récursive
void detruire_r(Liste l) {
	if(l->suiv == NULL){
		detruireElement(l->val);
		free(l);
	}
	else{
		detruire_r(l->suiv);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste tmp = l;
	if(l != NULL){
		Liste s;
		s=creer(v);
		while(l->suiv!=NULL){
		l=l->suiv;
		}
	l->suiv=s;
	}
	else{
		tmp=ajoutTete(v,l);
	}
	return tmp;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(l == NULL){
		l=creer(v);
	}
	else{
		if(l->suiv != NULL){
			ajoutFin_r(v, l->suiv);
		}
		else{
			Liste s = creer(v);
			l->suiv=s;
		}
	}
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(l!=NULL){
		if(equalsElement(v, l->val)){
			return l;
		}
		else{
			l=l->suiv;
		}
	}
	return NULL;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(l == NULL){
		return NULL;
	}
	if(equalsElement(v, l->val)){
		return l;
	}
	else {
		l=cherche_r(v, l->suiv);
	}
	return l;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste tmp = l;
	if(cherche_i(v,l)!=NULL){ // A ne plus faire 
		if(l->val == v){
			tmp=tmp->suiv;
			detruireElement(l->val);
			free(l);
			l=NULL;
			return tmp;
		}
		while(l->suiv->val != v){
			l=l->suiv;
		}
		Liste newSuiv = l->suiv->suiv;
		free(l->suiv);
		l->suiv = newSuiv;	
	}
	return tmp;
	
	
	
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(cherche_r(v,l)!=NULL){
		if(l->val == v){
			Liste tmp = l->suiv;
			detruireElement(l->val);
			free(l);
			l=NULL;
			return tmp;
		}
		if(l->suiv->val==v){
			Liste newSuiv = l->suiv->suiv;
			free(l->suiv);
			l->suiv = newSuiv;
		}
		else{
			retirePremier_r(v,l->suiv);
		}
	}
	return l;
}


void afficheEnvers_r(Liste l) {
	if(l->suiv == NULL){
		afficheElement(l->val);
	}
    else{
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}

}



