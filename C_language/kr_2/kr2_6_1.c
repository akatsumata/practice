#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
	unsigned int x;
	unsigned int y;
	int p, n;
	
	x = 0;
	y = 23;
	p = 4;
	n = 3;
	x = setbits(x, p, n, y);
	printf("x = %d\n", x);

	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	x = y;
	y = x >> (p + 1 -n) & ~(~0 << n);
	x = x >> n;
	x = x << n;
	x = y | x;

	return x;
}
