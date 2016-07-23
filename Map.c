#include <stdio.h>
#include <stdlib.h>
#include "Unicode.h"
#include "Console.h"
#include "Draw.h"
#include "Life.h"
#include "Map.h"

void MapInit(MAP *map)
{
	map->life = NULL;
	map->row = 0;
	map->col = 0;
}

void MakeMap(MAP *map, CONSOLE *cons)
{
	int i, j;
	
	map->col = GetCols(cons)/2;  // unicode /2
	map->row = GetLines(cons)-1; // console boundary -1

	// column:i, row:j //
	map->life = (LIFE **)malloc(map->col * sizeof(LIFE));
	for (i=0; i<map->col; i++)
		map->life[i] = (LIFE *)malloc(map->row * sizeof(LIFE));

	for (i=0; i<map->col; i++)
	{
		for (j=0; j<map->row; j++)
		{
			SetState(&(map->life[i][j]), DEATH);
			SetNear(&(map->life[i][j]), 0);
		}
	}
}

int GetRow(MAP *map)
{
	return map->row;
}

int GetCol(MAP *map)
{
	return map->col;
}

LIFE *GetLife(MAP *map, int x, int y)
{
	return &(map->life[x][y]);
}

void SetRow(MAP *map, int row)
{
	map->row = row;
}

void SetCol(MAP *map, int col)
{
	map->col = col;
}

void DestroyMap(MAP *map)
{
	int i;
	for (i=0; i<map->col; i++)
		free(map->life[i]);
	free(map->life);
}
