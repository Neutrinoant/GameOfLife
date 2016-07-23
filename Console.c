#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "Console.h"

void ConsInit(CONSOLE *cons)
{
	cons->lines = DEFAULT_CON_LINES;
	cons->cols = DEFAULT_CON_COLS;
}

int GetLines(CONSOLE *cons)
{
	return cons->lines;
}

int GetCols(CONSOLE *cons)
{
	return cons->cols;
}

void SetLines(CONSOLE *cons, int lines)
{
	cons->lines = lines;
}

void SetCols(CONSOLE *cons, int cols)
{
	cons->cols = cols;
}

void gotoxy(int x, int y)
{
	COORD pos = {x-1, y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int curposx()
{
	HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;
	GetConsoleScreenBufferInfo(consoleHandler, &screenInfo);
	return screenInfo.dwCursorPosition.X + 1;
}

int curposy()
{
	HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;
	GetConsoleScreenBufferInfo(consoleHandler, &screenInfo);
	return screenInfo.dwCursorPosition.Y + 1;
}
