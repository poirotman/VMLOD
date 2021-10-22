// gcc -W -Wall -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main
// gcc -W -Wall -Wno-unused-parameter -std=c99 liste-chainee.c liste-chainee-main.c -o liste-chaine-main

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
// Fonctions Externes

//Affichage d'un element
void afficheElement(Element e){
	e=(char*)e;
	printf("%s\n", e);
}

//Detruit l'élément e
void detruireElement(Element e){
}

//compare deux éléments
bool equalsElement(Element e1, Element e2){
	e1=(char*)e1;
	e2=(char*)e2;
	if(strcmp(e1,e2)){
		return false;
	}
	else{
		return true;
	}
}

int main(void){
	Liste l, p;
	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");
	

	l = ajoutTete("Test1",l);
	l = ajoutTete("Test2",l);
	l = ajoutTete("Test3",l);
	l = ajoutTete("Test4",l);
	l = ajoutTete("Test5",l);
	l = ajoutTete("Test1",l);
	l = ajoutTete("Test4",l);
	l = ajoutTete("Test8",l);
	l = ajoutTete("Test1",l);

	afficheListe_r(l);

	ajoutFin_i("GrandTest1",l);
	afficheListe_i(l);
	ajoutFin_r("GrandTest2",l);
	afficheListe_i(l);

	p = cherche_i("Ceci n'existe pas",l);
	printf("cherche_i(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i("GrandTest1",l);
	if(estVide(p))
	printf("cherche_i(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(99) : trouve ");
		afficheElement(p->val);
	 	printf("\n");
	}

	p = cherche_r("Ceci n'existe pas",l);
	printf("cherche_r(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r("GrandTest1",l);
	if(estVide(p))
		printf("cherche_r(99) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(99) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(1)   : ");
	l = retirePremier_i("Test1",l);
	afficheListe_r(l);

	printf("retirePremier_i(1)   : ");
	l = retirePremier_i("Test1",l);
	afficheListe_r(l);

	printf("retirePremier_i(100) : ");
	l = retirePremier_i("GrandTest2",l);
	afficheListe_r(l);

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r("Test4",l);
	afficheListe_r(l);

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r("Test4",l);
	afficheListe_r(l);

	printf("retirePremier_r(99)  : ");
	l = retirePremier_r("GrandTest1",l);
	afficheListe_r(l);

	detruire_r(l);
	l = NULL;
	

	return EXIT_SUCCESS;
}