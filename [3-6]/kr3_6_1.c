#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itoa(unsigned n, char s[], int b);
void reverse(char s[]);

int main()
{
	char s[MAXLINE];
	int n;

	n = 100;
	itoa(n, s, 8);
	printf("value n = %d\na minimum field width = 8\narray s = %s\n", n, s);
	return 0;
}

void itoa(unsigned n, char s[], int c)
{
	int i, sign;


	if((sign = n) < 0){
		n = -n;
	}
	i = 0;
	do{
		s[i++] = n % 10 + '0';
		c = c - 1;
	} while((n /= 10) > 0);
	if(sign < 0){
		s[i++] = '-';
		c = c - 1;
	}
	while(c > 0){
		++i;
		--c;
		s[i] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;	
	}
}
