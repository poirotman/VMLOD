
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Music *createMusic(char* line){
    Music *musique= calloc(1,sizeof(Music));
    char *copy=strdup(line);
    musique->name = strsep(&copy,",");
    //printf("%s\n",musique->name);

    musique->artist = strsep(&copy,",");
    //printf("%s\n",musique->artist);

    musique->album = strsep(&copy,",");
    //printf("%s\n",musique->album);

    musique->genre = strsep(&copy,",");
    //printf("%s\n",musique->genre);

    musique->discNumber = atoi( strsep(&copy,","));
    // printf("%i\n",musique->discNumber);

    musique->trackNumber = atoi( strsep(&copy,","));
    // printf("%i\n",musique->trackNumber);

    musique->year = atoi( strsep(&copy,","));
    // printf("%i\n",musique->year);
    
    return musique;
}

Liste createList(FILE *f, char* line,Liste ListMusic){
    fgets(line,255,f);
    Music *musique = calloc(1,sizeof(Music));
    musique = createMusic(line);
    ListMusic = ajoutFin_i(musique, ListMusic);
    return ListMusic;
}

void afficheElement(Element e){
    Music *m = (Music*)e; 
    printf("%s,", m->name);
    printf("%s,", m->artist);
    printf("%s,", m->album);
    printf("%s,", m->genre);
    if(m->discNumber == 0){
        printf(",");
    }
    else{
        printf("%i,", m->discNumber);
    }
    printf("%i,", m->trackNumber);
    printf("%i\n", m->year);
}
void detruireElement(Element e){
    Music *m = (Music*)e; 
    // free(m->name);
    // free(m->artist);
    // free(m->album);
    // free(m->genre);
    free(m);
    e=NULL;
    
}
bool equalsElement(Element e1, Element e2){
    Music *m1 = (Music *)e1;
    Music *m2 = (Music *)e2;
    if(strcmp(m1->name, m2->name) != 0){
        return false;
    }
    if(strcmp(m1->name, m2->artist) != 0){
        return false;
    }
    if(strcmp(m1->name, m2->album) != 0){
        return false;
    }
    if(strcmp(m1->name, m2->genre) != 0){
        return false;
    }
    if((m1->discNumber != m2->discNumber)){
        return false;
    }
    if((m1->trackNumber != m2->trackNumber)){
        return false;
    }
    if((m1->year != m2->year)){
        return false;
    }
    return true;

}