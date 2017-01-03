/* Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal, a vertical
orientation is more challenging */

/* Counts occurrences of each digit, of white space characters, and of all
other characters - thus 12 categories of input 
can pipe stuff in and out with cat 1-13.c | ./a.out > test resulting in
digits = 9 4 1 0 0 0 0 0 0 1, white space = 178, other = 597 for example
*/

#include <stdio.h>

/* counts digits, white spaces, others */
main()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	printf("digits =");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}