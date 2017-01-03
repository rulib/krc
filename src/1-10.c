/* Write a program to copy its input to its output, 
replacing each tab by \t, each backspace by \b, and each backslash by \\.
This makes tabs and backspaces visible in an unambiguous way
 */

#include <stdio.h>

main()
{
	int c;

while ((c = getchar()) != EOF) {
		if (c == '\t'){
			putchar(0x5C);
			putchar(0x74);
		}
		if (c == '\\'){
			putchar(0x5C);
			putchar(0x5C);
		}
		if (c == '\b'){
			putchar(0x5C);
			putchar(0x62);
		}
		if (c != '\b' && c != '\\' && c != '\t'){
			putchar(c);
		}

	}
}
