// Simple calculator that implements +,-,*,/ using reverse Polish Notation for
// positive integers only as input but any integer as output!
//@Author: Edoardo Bertoli

#include "stack.h"
#include <stdio.h>

#define isnumber(n) (n >= 48 && n <= 57) // Example of a function as a macro

int main(void) {
  /* Sweep through the input until EOF or '\n' (while)
     For each char do this: (switch char read from stdin)
     1. check if its number, operator or something else
     2. if number then push it onto stack, augment head by one
     3. if operator than pop two (each time decrementing head), calculate, push
     result (increment head)
     4. if is enter or EOF, print the top element of the stack and end,
     otherwise ignore and break out of switch. The stack is a global array of
     chars, the free position is saved as another global variable (head).

     Like this works only with integer numbers, I could then add a way to
     include double numbers written like 1234.23456... I could use the ungetc
     function from std library to distinguish between adjacent double numbers,
     like 123.3435_789.989898+ where I add the operator '_'(95 in dec) to signal
     the end of a double number. Then I could also add the operator mod % and
     provisions for negative numbers, also commands to clear the stack
  */

  printf("Enter the Reverse Polish expression you want to calculate (only "
         "positive integers as input, enter newline/return when done):\n");

  head = 0;

  int type;
  int counter = 0;
  while ((type = fgetc(stdin)) != '\n') {
    counter++;
    if (isnumber(type)) {
      push(type - 48); // conversion 48 -> 57 to 0 -> 9
    } else {
      int temp1, temp2;
      switch (type) {
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
        if (temp1 == 0) {
          fprintf(stderr, "[ERROR] Cannot divide by zero!\n");
          exit(EXIT_FAILURE);
        } else {
          push(temp2 / temp1);
        }
        break;
      default:
        fprintf(stderr,
                "\n[ERROR] Unknown operator or operand. Please check input at "
                "position %d.\n",
                counter);
        exit(EXIT_FAILURE);
        break;
      }
    }
  }

  if (head == 0 || head >= MAXOP) {
    fprintf(stderr, "[ERROR] Something went wrong, check input!\n");
  } else {
    printf("The given expression evaluates to: %d\n", pop());
  }

  return 0;
}
