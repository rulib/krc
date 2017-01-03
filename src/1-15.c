#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int f2c (float f);
float fahr, celsius;

/* test power function */
main()
{
	fahr = LOWER;
	while (fahr <= UPPER) {
		celsius = f2c(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr += STEP;
	}
}

int f2c(float f)
{
	return (5.0/9.0) * (f-32.0);
}

/*
return-type function-name(parameter declarations, if any)
{
	declarations
	statements
}
*/