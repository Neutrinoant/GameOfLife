#include <stdio.h>
#include "Console.h"
#include "Unicode.h"
#include "Map.h"

int c2mx(int conx)
{
	return conx/2;
}

int c2my(int cony)
{
	return cony-1;
}

int isInterior(MAP *map, int mx, int my)
{
	if ((1<=mx && mx<map->col-2) && (1<=my && my<map->row-2))
		return 1;
	return 0;
}

int isBoundary(MAP *map, int mx, int my)
{
	if ((mx==1 || mx==map->col-2) || (my==1 && my==map->row-2))
		return 1;
	return 0;
}

void modifyNearLife(MAP *map, int x, int y, int n)
{
	map->life[x-1][y-1].nearlife+=n;
	map->life[x-1][y].nearlife+=n;
	map->life[x-1][y+1].nearlife+=n;
	map->life[x][y-1].nearlife+=n;
	map->life[x][y+1].nearlife+=n;
	map->life[x+1][y-1].nearlife+=n;
	map->life[x+1][y].nearlife+=n;
	map->life[x+1][y+1].nearlife+=n;
}

void makeLife(MAP *map)
{
	UNIC ch;
	int x, y;  // 2d position on map
	int n;

	gotoxy(3,2);

	unigetch(ch);
	while (!uniequal(ch, ENTER))
	{
		x = c2mx(curposx()); y = c2my(curposy());

		if (uniequal(ch, UP) && y != 1)
			gotoxy(curposx(), curposy()-1);
		else if (uniequal(ch, DOWN) && y != map->row-2)
			gotoxy(curposx(), curposy()+1);
		else if (uniequal(ch, LEFT) && x != 1)
			gotoxy(curposx()-2, curposy());
		else if (uniequal(ch, RIGHT) && x != map->col-2)
			gotoxy(curposx()+2, curposy());
		else if (uniequal(ch, SPACE))
		{
			if (map->life[x][y].state == DEATH) {
				map->life[x][y].state = LIVE;
				printf("■");  // curposx+=2
				gotoxy(curposx()-2, curposy());
				n = 1;
			}
			else {
				map->life[x][y].state = DEATH;
				printf("□");  // curposx+=2
				gotoxy(curposx()-2, curposy());
				n = -1;
			}

			modifyNearLife(map, x, y, n);
		}
		unigetch(ch);
	}
}
