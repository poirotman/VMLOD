#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	if(a==NULL){
		return true;
	}
	return false;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	(*a)=NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a;
	a=calloc(1,sizeof(Noeud));
	initialiser(&a->filsGauche);
	initialiser(&a->filsDroit);
	a->val=e;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire copy=a;
	if(estVide(copy)){
		a=creer(e);
		return a;
	}
	while(!estVide(copy) && e != copy->val){
		if(e<copy->val){
			if(!estVide(copy->filsGauche)){
				copy=copy->filsGauche;
			}
			else{
				copy->filsGauche=creer(e);
				return a;
			}
		}
		else{
			if(!estVide(copy->filsDroit)){
				copy=copy->filsDroit;
			}
			else{
				copy->filsDroit=creer(e);
				return a;
			}
		}
	}
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if(estVide(a)){
		a=creer(e);
		return a;
	}
	if(e==a->val){
		return a;
	}
	else{
		if(e<a->val){
			a->filsGauche=insere_r(a->filsGauche,e);
		}
		else{
			a->filsDroit=insere_r(a->filsDroit,e);
		}
	}
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if(estVide(a)){
		return 0;
	}
	else{
		return (nombreDeNoeud(a->filsDroit)+nombreDeNoeud(a->filsGauche)+1);
	}
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if(estVide(a)){
		return -1;
	}
	if(e==a->val){
		return 0;
	}
	else{
		if(e<a->val){
			if(profondeur(a->filsGauche,e)==-1){
				return -1;
			}
			return profondeur(a->filsGauche,e)+1;
		}
		else{
			if(profondeur(a->filsDroit,e)==-1){
				return -1;
			}
			return profondeur(a->filsDroit,e)+1;
		}
	}
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if(estVide(a)){
		return 0;
	}
	if(hauteur(a->filsGauche)>hauteur(a->filsDroit)){
		return hauteur(a->filsGauche)+1;
	}
	else{
		return hauteur(a->filsDroit)+1;
	}
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){
	if(estVide(a)|| elem==a->val){
		return NULL;
	}
	if(a->val>elem){
		if(!estVide(a->filsGauche)){
			if(a->filsGauche->val==elem){
				return a;
			}
			else{
				return pere(a->filsGauche,elem);
			}
		}
		else{
			return NULL;
		}
	}
	else{
		if(!estVide(a->filsDroit)){
			if(a->filsDroit->val==elem){
				return a;
			}
			else{
				return pere(a->filsDroit,elem);
			}
		}
		else{
			return NULL;
		}
	}
}


void afficheRGD_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("%i ",a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
		}
}

void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		afficheGRD_r(a->filsGauche);
		printf("%i ",a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a){
	if(!estVide(a)){
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
		printf("%i ",a->val);
		}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	if(estVide(a)){
		return NULL;
	}
	else{
		while(a->filsGauche != NULL){
			a=a->filsGauche;
		}
	}
	return a;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	if(estVide(a)){
		return NULL;
	}
	else{
		while(!estVide(a->filsDroit)){
			a=a->filsDroit;
		}
	}
	return a;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){
	if(estVide(a)){
		return NULL;
	}
	if(elem==a->val){
		return a;
	}
	else{
		if(elem<a->val){
			return recherche_r(a->filsGauche,elem);
		}
		else{
			return recherche_r(a->filsDroit,elem);
		}
	}
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x){
	if(!estVide(a)){
		ArbreBinaire papa = pere(a,x);
		ArbreBinaire copy;
		if(pere != NULL){
			if(!estVide(papa->filsDroit)){
				if(papa->filsDroit->val == x){
					if(!estVide(papa->filsDroit->filsDroit)){
						copy=min(papa->filsDroit->filsDroit);
						free(papa->filsDroit);
						papa->filsDroit=copy;
					}
				}
			}
		}
	}
}

void detruire_r(ArbreBinaire a){
	if(!estVide(a->filsDroit)){
		detruire_r(a->filsDroit);
	}
	if(!estVide(a->filsGauche)){
		detruire_r(a->filsGauche);
	}
	free(a);
	a=NULL;
}

