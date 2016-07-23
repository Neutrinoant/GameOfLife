#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#define DEFAULT_CON_LINES 26
#define DEFAULT_CON_COLS 80

typedef struct console {
	int lines;
	int cols;
} CONSOLE;

void ConsInit(CONSOLE *cons);
int GetLines(CONSOLE *cons);
int GetCols(CONSOLE *cons);
void SetLines(CONSOLE *cons, int lines);
void SetCols(CONSOLE *cons, int cols);
void gotoxy(int x, int y);
int curposx();
int curposy();

#endif
