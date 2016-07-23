#ifndef __LIFE_H__
#define __LIFE_H__

#define LIVE 1
#define DEATH 0

typedef struct life {
	int state;     // life state
	int nearlife;  // # of near lives
} LIFE;


#endif
