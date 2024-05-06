#include <stdio.h>

const char* modes[] = {"newlines","tabs","blank spaces"};


int main(int argc, char** argv)
{
	if(argc < 2)
	{
		fprintf(stderr, "[ERROR] provide one argument between:\nn -> count newlines\nt -> count tabs\nb -> count blanks\n");
		return 1;
	}
	int sel = 0; //keep count of modes for last printf
	char counted = '\n'; //keep track of char to count

	const char chosen_mode = argv[1][0];
	switch(chosen_mode)
	{
		case 'n': counted = '\n'; sel = 0; break;
		case 't': counted = '\t'; sel = 1; break;
		default : counted = ' ' ; sel = 2; break;
	}


	int c;
	int nl = 0; 

	/*
	 *	BE CAREFUL: '\n' is a character constant, thus an integer in expressions,
	 *			"\n" is a string constant that contains only one char, DOES NOT WORK
	 *			as an integer like a char constant!
	 */
	while((c = getchar()) != EOF)
	{
		if(c == counted)
		{
			++nl;
		}
	}
	printf("There are %d %s in the input text.\n", nl, modes[sel]);

	return 0;
}
