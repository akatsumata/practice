#include <stdio.h>

int bitcount(unsigned x);

int main()
{
	int bit;
	unsigned x;

	x = 11;
	bit = bitcount(x);
	printf("%d\n", bit);

	return 0;
}

int bitcount(unsigned x)
{
	int bit;
	
	bit = 0;
	while(x != 0){
		x = x & (x - 1);
		bit++;
	}

	return bit;
}
