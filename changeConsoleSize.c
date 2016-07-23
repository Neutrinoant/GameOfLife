#include <stdio.h>
#include <stdlib.h>
#include "Unicode.h"
#include "Console.h"
#include "Draw.h"

#define MIN_CONS_LINES 7
#define MIN_CONS_COLS 30

int changeConsoleSize(CONSOLE *cons)
{
	UNIC ch;
	char *str;
	int cur_lines = cons->lines;
	int cur_cols = cons->cols;

	str = (char *)malloc(100 * sizeof(char));
	sprintf(str, "mode con: lines=%d cols=%d", cur_lines, cur_cols);
	system(str);  // initial console size
	drawConsoleSizeIntro();
	
	while (1)
	{
		unigetch(ch);
		
		if (uniequal(ch, UP))
		{
			if (cur_lines > MIN_CONS_LINES)
			{
				cur_lines-=1;
				sprintf(str, "mode con: lines=%d cols=%d", cur_lines, cur_cols);
			}
			system(str);
			drawConsoleSizeIntro();
		}
		else if (uniequal(ch, DOWN))
		{
			cur_lines+=1;
			sprintf(str, "mode con: lines=%d cols=%d", cur_lines, cur_cols);
			system(str);
			drawConsoleSizeIntro();
		}
		else if (uniequal(ch, LEFT))
		{
			if (cur_cols > MIN_CONS_COLS)
			{
				cur_cols-=2;
				sprintf(str, "mode con: lines=%d cols=%d", cur_lines, cur_cols);
			}
			system(str);
			drawConsoleSizeIntro();
		}
		else if (uniequal(ch, RIGHT))
		{
			cur_cols+=2;
			sprintf(str, "mode con: lines=%d cols=%d", cur_lines, cur_cols);
			system(str);
			drawConsoleSizeIntro();
		}
		else if (uniequal(ch, ENTER))
		{
			cons->lines = cur_lines;
			cons->cols = cur_cols;
			return 1;
		}
	}
	return 0;
}
