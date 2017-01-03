/* Word counter:
A word is any sequence of characters that does not contain a blank tab or 
newline - this is similar to wc.
Also counts lines and characters.
 */

/*
Testing the word count program:  
The word count program could be tested by subjected it to a series of unusual inputs
including numerous escape characters, whitespace, etc - trying not to test it 
only on "normal words".  The spec is sufficiently narrow that bugs aren't 
super obvious or likely.
*/

#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	/* initializes with state in OUT, so it will count the first word */
	nl = nw = nc = 0;
	while((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
