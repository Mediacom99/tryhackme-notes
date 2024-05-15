// Simple calculator that implements +,-,*,/ using reverse Polish Notation
// basically the operator follows the two operands, you keep doing that until you finish operators
// like (1 + 3) / (4 - 2) is written as 1 3 + 4 2 - /

#include <stdio.h>
#include <stdlib.h> //for atof

#define MAXOP 100 //Max size of operand or operator
#define NUMBER '0' //Signal that a number was found

int getop(char[]);
void push(double);
double pop(void);





