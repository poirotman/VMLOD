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


int main(void)
{

	//int nbGagnants = scanLineAsInt();
	//printf("nbGagnants = %i",nbGagnants);
	//EXO 1
	int nbGagnants;
	Winner *w;
	readWinners(&w, &nbGagnants);
	printWinners(&w, &nbGagnants);
	return EXIT_SUCCESS;
}
