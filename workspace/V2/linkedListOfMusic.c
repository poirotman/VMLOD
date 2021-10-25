#include "linkedList.h"
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void afficheElement(Element e){
    Music *m = (Music*)e; 
    printf("%s\n", m->name);
    printf("%s\n", m->artist);
    printf("%s\n", m->album);
    printf("%s\n", m->genre);
    printf("%i\n", m->discNumber);
    printf("%i\n", m->trackNumber);
    printf("%i\n", m->year);
}
void detruireElement(Element e){
    free(e);
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