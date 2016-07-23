#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#define DEFAULT_CON_LINES 26
#define DEFAULT_CON_COLS 80

typedef struct console {
	int lines;
	int cols;
} CONSOLE;

void initConsole(CONSOLE *cons);
void gotoxy(int x, int y);
int curposx();
int curposy();

#endif
