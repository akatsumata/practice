#include <stdio.h>

unsigned invert(unsigned x, int p , int n);

int main()
{
	unsigned x;
	int p, n;

	x = 32;
	p = 4;
	n = 3;
	x = (x, p ,n);
	printf("%d\n", x);
	return 0;
}

unsigned invert(unsigned x, int p , int n)
{
	return x ^ (~(~0 << n) << (p + 1 - n));
}
