/* Write a program that counts blanks, tabs, and newlines */

#include <stdio.h>

main()
{
	int c, bl, ta, nl;

	nl = 0;
	bl = 0;
	ta = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (c == ' ')
			++bl;
		if (c == '\t')
			++ta;
	}
	printf("Number of blanks: %d\n", bl);
	printf("Number of tabs: %d\n", ta);
	printf("Number of newlines: %d\n", nl);
}