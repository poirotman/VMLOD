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
	l->val = v;
	l->suiv = NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	if(l!=NULL){
		Liste s;
		s = creer(v);
		s->suiv = l ;
	}
	else{
		l->val = v;
	}
	return l;
}


void afficheElement(Element e) {
	printf("%i",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	if(l!=NULL){
		while( l->suiv !=NULL){
			afficheElement(l->val);
			l=l->suiv;
		}
	}
	else{
		
	}
	
}

// version recursive
void afficheListe_r(Liste l) {
	if(l!=NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
	else{
	}
}

void detruireElement(Element e) {
	e = NULL;
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	while(l!=NULL){
		l->val = NULL;
		l=l->suiv;
	}
}

// version récursive
void detruire_r(Liste l) {
	TODO;
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	return TODO;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	return TODO;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	return TODO;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	return TODO;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	return TODO;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	return TODO;
}


void afficheEnvers_r(Liste l) {
	TODO;
}


