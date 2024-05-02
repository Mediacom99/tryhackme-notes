#include <stdio.h>


int main() {


	int nc, c;

	nc = 0;
	while( (c = getchar()) != EOF)
	{
	
		if(c != '\n' && c != 32)
		{
		   ++nc;
		  fprintf(stdout,"You typed: %c\n", c);
		
		}
	}
	printf("\n\tYou typed %d chars\n\n", nc);
	return 0;
}
