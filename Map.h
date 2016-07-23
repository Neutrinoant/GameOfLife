#ifndef __MAP_H__
#define __MAP_H__

#include "Console.h"
#include "Life.h"

typedef struct map {
	LIFE **life;
	int row;
	int col;
} MAP;

void MapInit(MAP *map);
void MakeMap(MAP *map, CONSOLE *cons);
int GetRow(MAP *map);
int GetCol(MAP *map);
LIFE *GetLife(MAP *map, int x, int y);
void SetRow(MAP *map, int row);
void SetCol(MAP *map, int col);
void DestroyMap(MAP *map);

#endif
