#include <stdio.h>
#include <stdlib.h>
#include "Unicode.h"
#include "Console.h"
#include "Draw.h"
#include "Life.h"
#include "Map.h"
#include "MapConsoleTransform.h"

int isGetLive(MAP *map, int x, int y, int lifenum[])
{
	int i = 0;
	int c = lifenum[i];
	int nearnum = GetNear(GetLife(map,x,y));

	while (c != '\0') {
		if (nearnum == c)
			return 1;
		c = lifenum[i++];
	}

	return 0;
}

int isDeath(MAP *map, int x, int y)
{
	if (GetState(GetLife(map,x,y)) == DEATH)
		return 1;
	else
		return 0;
}

int isMoreLive(MAP *map, int x, int y, int keepnum[])
{
	int i = 0;
	int c = keepnum[i];
	int nearnum = GetNear(GetLife(map,x,y));

	while (c != '\0') {
		if (nearnum == c)
			return 1;
		c = keepnum[i++];
	}

	return 0;
}

int isLive(MAP *map, int x, int y)
{
	if (GetState(GetLife(map,x,y)) == LIVE)
		return 1;
	else
		return 0;
}

void modifyNearLife(MAP *map, int x, int y, int n);

void nextMap(MAP *map, int keepnum[], int lifenum[])
{
	int i, j;
	int row = GetRow(map);
	int col = GetCol(map);

	// Change state of lives //
	for (i=1; i<=col-2; i++)
	{
		for (j=1; j<=row-2; j++)
		{
			if (isLive(map,i,j) && !isMoreLive(map,i,j,keepnum))
			{
				SetState(GetLife(map,i,j), DEATH);
				gotoxy(m2cx(i),m2cy(j));
				printf("□");
			}
			else if (isDeath(map,i,j) && isGetLive(map,i,j,lifenum))
			{
				SetState(GetLife(map,i,j), LIVE);
				gotoxy(m2cx(i),m2cy(j));
				printf("■");
			}
		}
	}

	// Change state of lives //
	for (i=1; i<=col-2; i++)
		for (j=1; j<=row-2; j++)
			SetNear(GetLife(map,i,j), 0);

	// Initialize # of near lives //
	for (i=1; i<=col-2; i++)
		for (j=1; j<=row-2; j++)
			if (isLive(map,i,j))
				modifyNearLife(map, i, j, 1);
}

void makeLife(MAP *map);

int startGameOfLife(MAP *map, int keepnum[], int lifenum[])
{
	UNIC ch;
	UNIC m = {109,0};
	int row = GetRow(map);
	
	drawGameDescription(map);

	while (1)
	{
		gotoxy(29,row+1);

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
