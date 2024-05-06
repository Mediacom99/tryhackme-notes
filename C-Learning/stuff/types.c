#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("CHAR: %lu bits\n", sizeof(char)*8);
	printf("INT: %lu bits\n", sizeof(int)*8);
	printf("SHORT INT: %lu bits\n", sizeof(short int)*8);
	printf("LONG INT: %lu bits\n", sizeof(long int)*8);
	printf("FLOAT: %lu bits\n", sizeof(float)*8);
	printf("DOUBLE: %lu bits\n", sizeof(double)*8);
	printf("LONG DOUBLE: %lu bits\n", sizeof(long double)*8);

	printf("%lld", LLONG_MAX); //Some other nice macros in limits.h and stdint.h
	return 0;
}
