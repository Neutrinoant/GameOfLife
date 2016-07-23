#include "MapConsoleTransform.h"

int m2cx(int mapx)
{
	return mapx*2+1;
}

int m2cy(int mapy)
{
	return mapy+1;
}

int c2mx(int conx)
{
	return conx/2;
}

int c2my(int cony)
{
	return cony-1;
}
