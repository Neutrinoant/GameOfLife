#ifndef __UNICODE_H__
#define __UNICODE_H__

typedef char UNIC[2];  // UNIC = 2 char type

extern UNIC UP;
extern UNIC DOWN;
extern UNIC LEFT;
extern UNIC RIGHT;
extern UNIC ENTER;
extern UNIC SPACE;
extern UNIC ESC;

int unigetchar(UNIC memory);
int unigetch(UNIC memory);
int unisetchar(UNIC memory, UNIC data);
int uniequal(UNIC data1, UNIC data2);
int uniputc(UNIC memory);
int uniputd(UNIC memory);

#endif
