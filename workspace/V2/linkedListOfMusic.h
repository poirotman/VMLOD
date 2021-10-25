#pragma once

#include "linkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music{
	char* name;
	char* artist;
	char* album;
	char* genre;
	int discNumber;
	int trackNumber;
	int year;
} Music;

//Fonction qui créer la Liste de Music
Liste createList(FILE *f, char* line,Liste ListMusic);

//Fontcion qui créer une musique
Music *createMusic(char* line);