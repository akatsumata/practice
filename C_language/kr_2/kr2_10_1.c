#include <stdio.h>

int lower(int c);

int main()
{
	int c, lower_c;
	c = 'C';

	lower_c = lower(c);
	printf("%c\n", lower_c);
	return 0;
}

int lower(int c)
{
	return(c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
