#include <stdio.h>
#include <stdlib.h>
#include "Unicode.h"
#include "Console.h"
#include "Draw.h"
#include "Life.h"
#include "Map.h"

void initMap(MAP *map)
{
	map->life = NULL;
	map->row = 0;
	map->col = 0;
}

void makeMap(MAP *map, CONSOLE *cons)
{
	int i, j;
	
	map->col = cons->cols/2;  // unicode /2
	map->row = cons->lines-1; // console boundary -1

	// column:i, row:j //
	map->life = (LIFE **)malloc(map->col * sizeof(LIFE));
	for (i=0; i<map->col; i++)
		map->life[i] = (LIFE *)malloc(map->row * sizeof(LIFE));

	for (i=0; i<map->col; i++)
	{
		for (j=0; j<map->row; j++)
		{
			map->life[i][j].state = DEATH;
			map->life[i][j].nearlife = 0;
		}
	}
}

void destroyMap(MAP *map)
{
	int i;
	for (i=0; i<map->col; i++)
		free(map->life[i]);
	free(map->life);
}
