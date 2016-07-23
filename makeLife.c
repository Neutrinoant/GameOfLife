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
	if ((1<=mx && mx<GetCol(map)-2) && (1<=my && my<GetRow(map)-2))
		return 1;
	return 0;
}

int isBoundary(MAP *map, int mx, int my)
{
	if ((mx==1 || mx==GetCol(map)-2) || (my==1 && my==GetRow(map)-2))
		return 1;
	return 0;
}

void modifyNearLife(MAP *map, int x, int y, int n)
{
	SetNear(GetLife(map,x-1,y-1), GetNear(GetLife(map,x-1,y-1)) + n);
	SetNear(GetLife(map,x-1,y), GetNear(GetLife(map,x-1,y)) + n);
	SetNear(GetLife(map,x-1,y+1), GetNear(GetLife(map,x-1,y+1)) + n);
	SetNear(GetLife(map,x,y-1), GetNear(GetLife(map,x,y-1)) + n);
	SetNear(GetLife(map,x,y+1), GetNear(GetLife(map,x,y+1)) + n);
	SetNear(GetLife(map,x+1,y-1), GetNear(GetLife(map,x+1,y-1)) + n);
	SetNear(GetLife(map,x+1,y), GetNear(GetLife(map,x+1,y)) + n);
	SetNear(GetLife(map,x+1,y+1), GetNear(GetLife(map,x+1,y+1)) + n);
}

void makeLife(MAP *map)
{
	UNIC ch;
	int x, y;  // position on map
	int n;

	gotoxy(3,2);

	unigetch(ch);
	while (!uniequal(ch, ENTER))
	{
		x = c2mx(curposx()); y = c2my(curposy());

		if (uniequal(ch, UP) && y != 1)
			gotoxy(curposx(), curposy()-1);
		else if (uniequal(ch, DOWN) && y != GetRow(map)-2)
			gotoxy(curposx(), curposy()+1);
		else if (uniequal(ch, LEFT) && x != 1)
			gotoxy(curposx()-2, curposy());
		else if (uniequal(ch, RIGHT) && x != GetCol(map)-2)
			gotoxy(curposx()+2, curposy());
		else if (uniequal(ch, SPACE))
		{
			if (GetState(GetLife(map,x,y)) == DEATH) {
				SetState(GetLife(map,x,y), LIVE);
				printf("■");  // curposx+=2
				gotoxy(curposx()-2, curposy());
				n = 1;
			}
			else {
				SetState(GetLife(map,x,y), DEATH);
				printf("□");  // curposx+=2
				gotoxy(curposx()-2, curposy());
				n = -1;
			}

			modifyNearLife(map, x, y, n);
		}
		unigetch(ch);
	}
}
