#include <stdio.h>

int main(void)
{

	int c;
	int temp;

	c = getchar();
	while(c != EOF)
	{
		if(putchar(c) != EOF)
		{
		c = getchar();
		}
		else
		{
		fprintf(stderr, "[ERROR] putchar method return EOF (tf did you get here ?)");
		return 1;
		}
	}
	
	printf("[INFO] exited successfully!");
	return 0;
}
