#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Console.h"
#include "Unicode.h"
#include "Draw.h"
#include "Life.h"
#include "Map.h"

int changeConsoleSize(CONSOLE *cons);
int makeRule(MAP *map, int keepnum[], int lifenum[]);
void makeLife(MAP *map);
int startGameOfLife(MAP *map, int keepnum[], int lifenum[]);

int main(void)
{
	MAP *map = (MAP *)malloc(sizeof(MAP));
	CONSOLE *cons = (CONSOLE *)malloc(sizeof(CONSOLE));
	int ruleOfLife[9+1];
	int ruleOfDeath[9+1];

	MapInit(map);
	ConsInit(cons);

	// 1. 창 조절
	changeConsoleSize(cons);

	// 2. 배경 세팅
	MakeMap(map, cons);
	drawMapBoundary(map);

	// 3. 규칙 설정
	if (makeRule(map, ruleOfLife, ruleOfDeath) < 0)
	{
		printf("Invalid rule...exit");
		fflush(stdin);
		getchar();
		exit(1);
	}

	// 4. 생명 위치 결정
	drawMapInterior(map);
	makeLife(map);

	// 5. 게임 시작
	startGameOfLife(map, ruleOfLife, ruleOfDeath);

	// 6. 게임 종료
	DestroyMap(map);

	return 0;
}
