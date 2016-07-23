#include "Life.h"

int GetState(LIFE *life)
{
	return life->state;
}

int GetNear(LIFE *life)
{
	return life->nearlife;
}

void SetState(LIFE *life, int state)
{
	life->state = state;
}

void SetNear(LIFE *life, int near)
{
	life->nearlife = near;
}
