#ifndef __DRAW_H__
#define __DRAW_H__

#include "Console.h"
#include "Map.h"

void drawConsoleSizeIntro(void);
void drawMapBoundary(MAP *map);
void drawRule(MAP *map);
void drawMapInterior(MAP *map);
void drawGameDescription(MAP *map);
void drawModifyMode(MAP *map);

#endif
