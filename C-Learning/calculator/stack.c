#include "stack.h"

int head;
int stack[MAXOP];

//Pop top element
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
