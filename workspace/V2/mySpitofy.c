#include <stdio.h>
#include <stdlib.h>
#include "linkedListOfMusic.h"
#include <string.h>
Music *creerMusique(char* l){
    char *cpyl = strdup(l);
    char *freecpyl=cpyl;
    char *cpysep;
    Music *musique=calloc(1, sizeof(Music));

    cpysep = strsep(&cpyl,",");
    musique->name = calloc(strlen(cpysep)+1, sizeof(char) );
    strcpy(musique->name , cpysep);

    cpysep = strsep(&cpyl,",");
    musique->artist = calloc(strlen(cpysep)+1, sizeof(char) );
    strcpy(musique->artist , cpysep);

    cpysep = strsep(&cpyl,",");
    musique->album = calloc(strlen(cpysep)+1, sizeof(char) );
    strcpy(musique->album , cpysep);

    cpysep = strsep(&cpyl,",");
    musique->genre = calloc(strlen(cpysep)+1, sizeof(char) );
    strcpy(musique->genre , cpysep);

    musique->discNumber = atoi(strsep(&cpyl,","));
    musique->trackNumber = atoi(strsep(&cpyl,","));
    musique->year = atoi(strsep(&cpyl,","));

    free(freecpyl);
    return musique;
}

Liste createListOfMusic(FILE* f, char* l,Liste ListMusic){
    fgets(l,250,f);
    Music *musique=(Music *)malloc(sizeof(Music));
    musique = creerMusique(l);
    ListMusic=ajoutFin_i(musique,ListMusic);
    return ListMusic;
}

int main(){
    char* fileName = "music.csv";
    FILE* f;
    f = fopen(fileName,"r");
    Liste ListMusic = NULL;
    char *line = calloc(8, sizeof(char*));
    
    
    printf("%s", fgets(line,250,f));
    
    for(int i=0; i<2700; i++){
        ListMusic=createListOfMusic(f,line,ListMusic);
    }
    afficheListe_i(ListMusic);
    
    
    fclose(f);
    free(line);
    detruire_i(ListMusic);


    return 0;
}