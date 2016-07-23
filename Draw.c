#include <stdio.h>
#include <stdlib.h>
#include "Console.h"
#include "Draw.h"
#include "Map.h"

void drawConsoleSizeIntro(void)
{
	printf("* Screen Size *\n"
		   " use ArrowKey  \n"
		   " & press Enter \n"
		   " default:26*80 \n");
}

void drawMapBoundary(MAP *map)
{
	int i, j;
	int col = GetCol(map);
	int row = GetRow(map);

	system("cls");

	printf("┌");
	for (j=1; j<=col-2; j++) printf("─");
	printf("┐");

	for (i=1; i<row-1; i++)
	{
		printf("│");
		for (j=1; j<=col-2; j++) printf("　");
		printf("│");
	}

	printf("└");
	for (j=1; j<=col-2; j++) printf("─");
	printf("┘");

	gotoxy(3,2);
}

void drawRule(MAP *map)
{
	gotoxy(3,2); printf("[Life]  : ");
	gotoxy(3,3); printf("[Death] : ");
	gotoxy(13,2);
}

void drawMapInterior(MAP *map)
{
	int i, j;
	int row = GetRow(map);
	int col = GetCol(map);

	for (j=1; j<=row-2; j++)
	{
		gotoxy(3,j+1);
		for (i=1; i<=col-2; i++)
			printf("□");
	}
}

void drawGameDescription(MAP *map)
{
	int i;
	int col = GetCol(map);
	gotoxy(3,GetRow(map)+1);
	printf("[ Enter:next | m:modify ] ");
	for (i=29; i<col*2-1; i+=2)
		printf("　");
}

void drawModifyMode(MAP *map)
{
	int i;
	int col = GetCol(map);
	gotoxy(3,GetRow(map)+1);
	printf("[ ...Modify Mode... ] ");
	for (i=25; i<col*2-1; i+=2)
		printf("　");
}
