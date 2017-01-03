/* Write a program to print a histogram of the frequency
 of characters in its input. */

#include <stdio.h>

main()
{
	int c, i, j, others;
	int chars[94];
	others = 0;

	for(i = 0; i < 94; ++i)
		chars[i] = 0;

	while ((c = getchar()) != EOF){
		if (c >= '!' && c <= '~')
			++chars[c - 33];
		else
			++others;
	}

	for (i = 0; i < 94; ++i){
	/* Prints legend */
		printf("%c: ", i + 33);
		for (j = 0; j < chars[i]; ++j){
			printf("O");
		}
		printf("\n");
	}

	printf("Other Chars: %d\n", others);
}