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

	system("cls");

	printf("┌");
	for (j=1; j<=map->col-2; j++) printf("─");
	printf("┐");

	for (i=1; i<map->row-1; i++)
	{
		printf("│");
		for (j=1; j<=map->col-2; j++) printf("　");
		printf("│");
	}

	printf("└");
	for (j=1; j<=map->col-2; j++) printf("─");
	printf("┘");

	gotoxy(3,2);
}

// 창에 맞게 표시하는 방법 추가바람
void drawRule(MAP *map)
{
	gotoxy(3,2); printf("[Life]  : ");
	gotoxy(3,3); printf("[Death] : ");
	gotoxy(13,2);
}

void drawMapInterior(MAP *map)
{
	int i, j;

	for (j=1; j<=map->row-2; j++)
	{
		gotoxy(3,j+1);
		for (i=1; i<=map->col-2; i++)
			printf("□");
	}
}

void drawGameDescription(MAP *map)
{
	int i;
	gotoxy(3,map->row+1);
	printf("[ Enter:next | m:modify ] ");
	for (i=29; i<map->col*2-1; i+=2)
		printf("　");
}

void drawModifyMode(MAP *map)
{
	int i;
	gotoxy(3,map->row+1);
	printf("[ ...Modify Mode... ] ");
	for (i=25; i<map->col*2-1; i+=2)
		printf("　");
}
