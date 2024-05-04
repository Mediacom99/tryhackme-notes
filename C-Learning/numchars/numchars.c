#include <stdio.h>


int count_chars(void) {


	int nc, c;

	nc = 0;
	while( (c = getchar()) != EOF)
	{
		// Count only ASCII printable chars
		if(c >= 32 && c<= 126) 
		{
		   ++nc;
		  //fprintf(stderr,"You typed: %c\n", c);
		
		}
	}
	return nc;
}

int main(void) 
{
	printf("\n\tYou typed %d ASCII printable chars\n\n", count_chars());
}
