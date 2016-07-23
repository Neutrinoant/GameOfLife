#include <stdio.h>
#include "Console.h"
#include "Unicode.h"
#include "Draw.h"
#include "Life.h"

int digitlen(int pn)
{
	int count = 0;
	if (pn == 0)
		return 1;
	else
		while (pn != 0)
		{
			count++;
			pn /= 10;
		}
	return count;
}

void initRule(int keepnum[], int lifenum[])
{
	int i;
	for (i=0; i<10; i++)
	{
		keepnum[i] = 0;
		lifenum[i] = 0;
	}
}

// Need to modify wrong input
// 1. duplicated (ex: 22334)
// 2. long number (ex: 123456789123452461646526...)
int makeRule(MAP *map, int keepnum[], int lifenum[])
{
	int temp;
	int knum, lnum;
	int keeplen, lifelen;
	int i;

	drawRule(map);
	initRule(keepnum, lifenum);

	// Keep num setting //
	scanf("%d", &knum);
	keeplen = digitlen(knum);
	while (keeplen > 9) {  // if above 9 numbers, admit 9 numbers only
		knum /= 10;
		keeplen--;
	}
	temp = knum;

	i = 0;
	while (temp != 0) {
		keepnum[i++] = temp % 10;
		temp /= 10;
	}
	
	gotoxy(13, 3);

	// Life num setting //
	scanf("%d", &lnum);
	lifelen = digitlen(lnum);
	while (lifelen > 9) {  // if above 9 numbers, admit 9 numbers only
		lnum /= 10;
		lifelen--;
	}
	temp = lnum;

	i = 0;
	while (temp != 0) {
		lifenum[i++] = temp % 10;
		temp /= 10;
	}

	gotoxy(3, 4);

	// Check invalid input //
	for (i=0; i<keeplen; i++)
		if (keepnum[i]<0 || keepnum[i]>8)
			return -1;  // invalid value
	for (i=0; i<lifelen; i++)
		if (lifenum[i]<0 || lifenum[i]>8)
			return -1;  // invalid value

	printf("Rule:%d/%d", knum, lnum);
	gotoxy(3, 5);
	printf("...press Enter");
	fflush(stdin);
	getchar();
	
	return 0;  // valid
}
