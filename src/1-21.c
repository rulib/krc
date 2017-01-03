/* Entab - replaces blanks with tabs (each tab stop is 8 spaces long) 

Anatomy of a line:
Character Number:
		  1111111
01234567890123456...

Tab stop:
00000000111111112...
*/

#include <stdio.h>

int main(void)
{
	printf("1234567890\n");
	printf("0\t1\t\n");
}