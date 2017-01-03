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

From "The C Answer Book":

To test the word count program first try no input,
The output should be: 0 0 0 (zero newlines, zero words, zero characters).
Then try a one-character word. The output should be: 1 1 2.
(one new line,one word, two characters-a letter followed by
a new line character). Then try a two character word.
the output should be: 1 1 3 (one new line, one word,
three chacters- two chacters followed by a new line character).
In addition, try 2 one-chacter words (the output should be 1 2 4) and
2 one-character words-one word per line(the output should be 2 2 4).
The kinds of input most likely to uncover bugs are those that test boudary
conditions. Some boundaries are:

-no input
-no words-just new lines
-no words-just blanks, tabs, and newlines
-one word per a line-no blanks and tabs
-word starting at the beginning of the line
-word starting after some blanks

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
