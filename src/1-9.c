/* Write a program to copy its input to its output, 
replacing each string of one or more blanks by a single blank */

#include <stdio.h>

main()
{
	int c, spc;
	spc = 0;

	while ((c = getchar()) != EOF) {
		/* first case: character is a space following a letter
			increment a counter of spaces to 1 and move on
		second case: character is a space following a space or series of spaces
			increment the space counter to 1+n and move on
		second case: character is a nonspace following a space or series of spaces
			set the counter of spaces to 0, print a space, print the character
		third case: character is a nonspace following a nonspace
			print the character without question
		*/
		if (c == ' ' && spc == 0)
			++spc;
		if (c == ' ' && spc > 0)
			++spc;
		if (c != ' ' && spc == 0) {
			putchar(c);
		}
		if (c != ' ' && spc > 0) {
			spc = 0;
			putchar(' ');
			putchar(c);
		}

	}
	
}