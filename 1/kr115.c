#include <stdio.h>

float ftoc(float f);
 
int main()
{
    float fahr, celsius;
    int lower, upper, step;
 
    lower = 0;
    upper = 300;
    step = 20;
 
    fahr = lower;
    printf("%s %s\n", "fahr", "celsius");
    while (fahr <= upper) {
        celsius = ftoc(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float ftoc(float f)
{
	float c;
	c = (5.0/9.0) * (f - 32.0);
	return c;
}

