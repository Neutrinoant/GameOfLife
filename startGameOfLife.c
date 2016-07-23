#include <stdio.h>
#include <stdlib.h>
#include "Unicode.h"
#include "Console.h"
#include "Draw.h"
#include "Life.h"
#include "Map.h"

int m2cx(int mapx)
{
	return mapx*2+1;
}

int m2cy(int mapy)
{
	return mapy+1;
}

int isGetLive(MAP *map, int x, int y, int lifenum[])
{
	int i = 0;
	int c = lifenum[i];
	int nearnum = map->life[x][y].nearlife;

	while (c != '\0') {
		if (nearnum == c)
			return 1;
		c = lifenum[i++];
	}

	return 0;
}

int isDeath(MAP *map, int x, int y)
{
	if (map->life[x][y].state == DEATH)
		return 1;
	else
		return 0;
}

int isMoreLive(MAP *map, int x, int y, int keepnum[])
{
	int i = 0;
	int c = keepnum[i];
	int nearnum = map->life[x][y].nearlife;

	while (c != '\0') {
		if (nearnum == c)
			return 1;
		c = keepnum[i++];
	}

	return 0;
}

int isLive(MAP *map, int x, int y)
{
	if (map->life[x][y].state == LIVE)
		return 1;
	else
		return 0;
}

void modifyNearLife(MAP *map, int x, int y, int n);

void nextMap(MAP *map, int keepnum[], int lifenum[])
{
	int i, j;

	// Change state of lives //
	for (i=1; i<=map->col-2; i++)
	{
		for (j=1; j<=map->row-2; j++)
		{
			if (isLive(map,i,j) && !isMoreLive(map,i,j,keepnum))
			{
				map->life[i][j].state = DEATH;
				gotoxy(m2cx(i),m2cy(j));
				printf("□");
			}
			else if (isDeath(map,i,j) && isGetLive(map,i,j,lifenum))
			{
				map->life[i][j].state = LIVE;
				gotoxy(m2cx(i),m2cy(j));
				printf("■");
			}
		}
	}

	// Initialize # of near lives //
	for (i=1; i<=map->col-2; i++)
		for (j=1; j<=map->row-2; j++)
			map->life[i][j].nearlife = 0;

	// Update # of near lives //
	for (i=1; i<=map->col-2; i++)
		for (j=1; j<=map->row-2; j++)
			if (isLive(map,i,j))
				modifyNearLife(map, i, j, 1);
}

void makeLife(MAP *map);

int startGameOfLife(MAP *map, int keepnum[], int lifenum[])
{
	UNIC ch;
	UNIC m = {109,0};
	
	drawGameDescription(map);

	while (1)
	{
		gotoxy(29,map->row+1);

		unigetch(ch);
		
		if (uniequal(ch, ENTER))
			nextMap(map, keepnum, lifenum);
		else if (uniequal(ch, m))
		{
			drawModifyMode(map);
			makeLife(map);
			drawGameDescription(map);
		}
		else if (uniequal(ch, ESC))
			return 0;
	}

	return 0;
}
