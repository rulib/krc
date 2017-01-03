#include <stdio.h>

main()
{
	int c;
	
	while ((c = getchar())) {
		printf("\nPrinting character c: %d %c\n", (c != EOF), c);
	}
}