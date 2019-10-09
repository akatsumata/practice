#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
	unsigned x;
	int n;
	x = 26;
	n = 3;
	x = rightrot(x, n);
	printf("%u\n", x);
	return 0;
}

unsigned rightrot(unsigned x, int n)
{
	int y, z;
	y = x >> n;
	z = x << (8 - n);
	x = y | z;
        return x;
}
