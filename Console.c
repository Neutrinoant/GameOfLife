#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "Console.h"

void initConsole(CONSOLE *cons)
{
	cons->lines = DEFAULT_CON_LINES;
	cons->cols = DEFAULT_CON_COLS;
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
