#ifndef __MAP_H__
#define __MAP_H__

#include "Console.h"
#include "Life.h"

typedef struct map {
	LIFE **life;
	int row;
	int col;
} MAP;

void initMap(MAP *map);
void makeMap(MAP *map, CONSOLE *cons);
void destroyMap(MAP *map);

#endif
