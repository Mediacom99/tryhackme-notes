/*
   Header-only library to implement a simple stack structure, with functions like pop, push and others.
 */


#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h> // for exit

#define MAXOP 256 //Max number of consecutive numbers possible
                  //(like 255 one's and 254 pluses would give you 255 as result)

int stack[MAXOP]; //stack used to store values and use them to do calculations
int head; //stores the position of the current head (top free position) of the stack

int pop(void);
void push(int num);

//Pop top element of the stack and return it
int pop(void)
{
  //Check if head is valid
  if(head <= MAXOP && head > 0)
    {
      --head;
      return stack[head];
    }
  else{
    fprintf(stderr, "[ERROR] Could not pop, head position counter is not valid! Exiting...\n");
    exit(EXIT_FAILURE);
  }
}

//Push num to top of stack
void push(int num)
{
    if(head <= MAXOP && head >= 0) {
    stack[head] = num;
    head++;
    return;
  }
  else {
    fprintf(stderr, "[ERROR] Could not push, head position counter is not valid! Exiting...\n");
    exit(EXIT_FAILURE);
  }
}

#endif
