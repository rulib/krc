/* Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal, a vertical
orientation is more challenging */

/*
For each word, we need to find the word, and count the length.  Then, 
lengths[length] can be incremented

Initially have the program simply output this array.

Finally, print the length, and then a number of Os to create the bar graph
*/

#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c, i, j, state, wordLength, longWords;
	int lengths[20];
	state = OUT;
	wordLength = longWords = 0;

	for(i = 0; i < 20; ++i)
		lengths[i] = 0;

/*Parse the word boundaries*/

	while ((c = getchar()) != EOF) {
		/* Leaving a word */
		if (c == '\n' || c == '\t' || c == ' ' && state == IN) {
			state = OUT;
			if (wordLength <= 20) 
				++lengths[wordLength - 1];
			else 
				++longWords;
			wordLength = 0;
		}
		/* Continuing in whitespace */
		else if (c == '\n' || c == '\t' || c == ' ')
			state = OUT;
		/* Entering a word */
		else if (state == OUT) {
			state = IN;
			++wordLength;
		}
		/* Continuing in a word */
		else if (state == IN) 
			++wordLength;
	}

	/* Just returns the stuff as text */
	for (i = 0; i < 20; ++i){
	/* Prints legend */
		printf("%d: ", i + 1);
		for (j = 0; j < lengths[i]; ++j){
			printf("O");
		}
		printf("\n");
	}

	printf("Long Words: %d\n", longWords);


}