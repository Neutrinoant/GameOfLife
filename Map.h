#ifndef __MAP_H__
#define __MAP_H__

#include "Console.h"
#include "Life.h"

typedef struct map {
	LIFE **life;
	int row;
	int col;
	int lastx;
	int lasty;
} MAP;

void MapInit(MAP *map);
void MakeMap(MAP *map, CONSOLE *cons);
int GetRow(MAP *map);
int GetCol(MAP *map);
int GetLastx(MAP *map);
int GetLasty(MAP *map);
LIFE *GetLife(MAP *map, int x, int y);
void SetRow(MAP *map, int row);
void SetCol(MAP *map, int col);
void SetLastx(MAP *map, int mx);
void SetLasty(MAP *map, int my);
void DestroyMap(MAP *map);

#endif
