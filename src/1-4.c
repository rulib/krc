#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;
	/* declaring integers */

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	/* assigning values */
	printf("Celsius to Fahrenheit\n");
	while (celsius <= upper) {
		fahr = (celsius/(5.0/9.0)) + 32;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	/* %d specifies integer arguments */
}

/*

Celsius to Fahrenheit
  0   32.0
 20   68.0
 40  104.0
 60  140.0
 80  176.0
100  212.0
120  248.0
140  284.0
160  320.0
180  356.0
200  392.0
220  428.0
240  464.0
260  500.0
280  536.0
300  572.0

*/