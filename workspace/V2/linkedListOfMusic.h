#pragma once

#include <stdbool.h>
#include "linkedList.h"

typedef struct music{
	char* name;
	char* artist;
	char* album;
	char* genre;
	int discNumber;
	int trackNumber;
	int year;
} Music;