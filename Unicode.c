#include <stdio.h>
#include <conio.h>
#include "Unicode.h"

extern UNIC UP = {-32,72};
extern UNIC DOWN = {-32,80};
extern UNIC LEFT = {-32,75};
extern UNIC RIGHT = {-32,77};
extern UNIC ENTER = {13,0};
extern UNIC SPACE = {32,0};
extern UNIC ESC = {27,0};

int unigetchar(UNIC memory)
{
    memory[0]=getchar();
    if(memory[0]<0){
        memory[1]=getchar();
        return 1;
    }
    return 0;
}

int unigetch(UNIC memory)
{
	memory[0]=_getch();
    if(memory[0]<0){
        memory[1]=_getch();
        return 1;
    }
    return 0;
}

int unisetchar(UNIC memory, UNIC data)
{
    memory[0]=data[0];
    if(memory[0]<0){
        memory[1]=data[1];
        return 1;
    }
    return 0;
}

int uniequal(UNIC data1, UNIC data2)
{
    if(data1[0]*data2[0]>=0&&data1[0]==data2[0])
        if(data1[0]>=0||data1[1]==data2[1])
            return 1;
    return 0;
}

int uniputc(UNIC memory)
{
    if(memory[0]<0){
        printf("%c%c",memory[0],memory[1]);
        return 1;
    }
    printf("%c",memory[0]);
    return 0;
}

int uniputd(UNIC memory)
{
    if(memory[0]<0){
        printf("%d %d",memory[0],memory[1]);
        return 1;
    }
    printf("%d",memory[0]);
    return 0;
}
