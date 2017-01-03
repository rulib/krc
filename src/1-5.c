#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20
/*
Symbolic constants are #defined in upper case and lacking a terminal semicolon, they are
not variables
*/

main()
{
int fahr;

for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
	printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

/*
Sample output:

300  148.9
280  137.8
260  126.7
240  115.6
220  104.4
200   93.3
180   82.2
160   71.1
140   60.0
120   48.9
100   37.8
 80   26.7
 60   15.6
 40    4.4
 20   -6.7
  0  -17.8

*/