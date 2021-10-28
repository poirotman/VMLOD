#include <stdio.h>
#include <stdlib.h>
#include "linkedListOfMusic.h"
#include <string.h>


int main(){
    char* fileName = "music.csv";
    FILE* f;
    f = fopen(fileName,"r");
    Liste ListMusic = NULL;
    char *line=calloc(250,sizeof(char));
    char *freeline = line;

    printf("%s",fgets(line, 250, f));
    ListMusic=createList(f,line,ListMusic);
    fclose(f);
    
    triParSelection(ListMusic);
    afficheListe_i(ListMusic);
    detruire_i(ListMusic);
    free(freeline);


    return 0;
}