// Simple calculator that implements +,-,*,/ using reverse Polish Notation
//@Author: Edoardo Bertoli

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100 //Max size of operands or operator 
 
int stack[MAXOP]; //Stack
int head = 0; //Free position on the stack

//Functions for stack manipulation
int pop(void);
void push(int);


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


int main(void)
{
  /* Sweep through the input until EOF or '\n' (while)
     For each char do this: (switch char read from stdin)
     1. check if its number, operator or something else
     2. if number then push it onto stack, augment head by one
     3. if operator than pop two (each time decrementing head), calculate, push result (increment head)
     4. if is enter or EOF, print the top element of the stack and end, otherwise ignore and break out of switch.
     The stack is a global array of chars, the free position is
     saved as another global variable (head).
     Could also do it using getline and malloc, check getline() on libc docs.

     Like this works only with integer numbers, I could then add a way to include double numbers written like 1234.23456...
     I could use the ungetc function from std library to distinguish between adjacent double numbers, like
     123.3435_789.989898+ where I add the operator '_'(95 in dec) to signal the end of a double number.
     Then I could also add the operator mod % and provisions for negative numbers, also commands to clear the stack
  */


  head = 0;

  printf("Enter the Reverse Polish expression you want to calculate (only positive integers as input, enter newline/return when done):\n");
  
  int type;
  while((type = fgetc(stdin)) != '\n')
    {
      if(type >= 48 && type <= 57)
	{
	  push(type - 48); //Conversion from value of ascii char to integer corresponding to the char (0 ~= 48)
	}
      else
	{
	  int temp1, temp2;
	  switch(type)
	    {
	    case '+':
	      temp1 = pop();
	      temp2 = pop();
	      push(temp2 + temp1);
	      break;
	    case '-':
	      temp1 = pop();
	      temp2 = pop();
	      push(temp2 - temp1);
	      break;
	    case '*':
	      temp1 = pop();
	      temp2 = pop();
	      push(temp2 * temp1);
	      break;
	    case '/':
	      temp1 = pop();
	      temp2 = pop();
	      if(temp1 == 0) {
		fprintf(stderr, "[ERROR] Cannot divide by zero! Exiting...\n"); exit(EXIT_FAILURE);
	      } else {
		push(temp2 / temp1);
	      }
	      break;
	    case ' ':
	      break;
	    default:
	      fprintf(stderr, "[ERROR] Unknown command, ignoring ascii: %c (0x%x)\n", type, type);
	      break;
	    }
	}
    }

  if(head == 0 || head >= MAXOP) {
    fprintf(stderr, "[ERROR] Something went wrong, check inpu! Exiting...\n");
  }
  else {
    printf("The given expression evaluates to: %d\n", pop());
  }
  
  return 0;
}



