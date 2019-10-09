#include <stdio.h>
#define MAXLINE 100

int main()
{
	int c, i, lim;
	char s[MAXLINE];

	for(i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
	printf("%d\n", i);

	return 0;
}

