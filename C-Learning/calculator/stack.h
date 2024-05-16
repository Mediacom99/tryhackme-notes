#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h> // for exit

#define MAXOP 256

extern int stack[MAXOP];
extern int head;

int pop(void);
void push(int num);

#endif
