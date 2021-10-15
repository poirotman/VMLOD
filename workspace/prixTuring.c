/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars until the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

// Question 1.
struct winner{
	int annee;
	char *noms;
	char *raison;
};
typedef struct winner Winner;

void readWinners(Winner **w, int *nbGagnant){
	*nbGagnant = scanLineAsInt();
	*w=(Winner *)calloc(*nbGagnant,sizeof(Winner));
	for(int i=0; i<*nbGagnant; i++){
		(*w)[i].annee = scanLineAsInt();
		(*w)[i].noms = scanLine();
		(*w)[i].raison = scanLine();
	}
}
void printWinners(Winner **w, int *nbGagnant){
	printf("%i\n", *nbGagnant);
	
	for(int i=0; i<*nbGagnant; i++){
		printf("%i\n",(*w)[i].annee);
		printf("%s\n",(*w)[i].noms);
		printf("%s\n",(*w)[i].raison);
	}
}

//Question 2.
int infosAnnee(int annee, Winner **w, int *nbGagnant){
	printf("annee: %i\n", annee);
	for(int i=0; i<*nbGagnant; i++){
		if((*w)[i].annee == annee){
			printf("L'annee %i, le(s) gagnant(s) ont été: %s\n", annee, (*w)[i].noms);
			printf("Nature des travaux : %s\n", (*w)[i].raison);
			return 0;
		}
	}
	printf("Aucunes donnée sur l'année: %i\n", annee);
	return 0;
}


int main(int argc, char *argv[])
{
	//int nbGagnants = scanLineAsInt();
	//printf("nbGagnants = %i",nbGagnants);
	//Question 1
	int nbGagnants;
	Winner *w;
	readWinners(&w, &nbGagnants);
	//Question 2
	int annee;
	if(argv[2]!=NULL && argv[1] != NULL){
		
		if (strcmp(argv[1] ,"infosAnnee")==0){
			sscanf(argv[2],"%i", &annee );
			printf("%i",annee);
			infosAnnee(annee, &w, &nbGagnants);
		}
	}
	else{
		printWinners(&w, &nbGagnants);
	}
	free(w);
	return EXIT_SUCCESS;
}
