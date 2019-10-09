#include <stdio.h>
#define MAXLINE 1000
void itoa(int n, char s[]);
int main()
{
    	char s1[MAXLINE], s2[MAXLINE];
    	int i1, i2;
    	i1 = -12;
    	printf("i1=%d\n", i1);
    	itoa(i1, s1);
    	printf("itoa i1=%s\n\n", s1);
    
	i2= 12;
    	printf("i2=%d\n", i2);
    	itoa(i2, s2);
    	printf("itoa i2=%s\n", s2);
    
	return 0;
}

void itoa(int n, char s[])
{
   	static int i;
    
    	if(n / 10) {
        	itoa(n / 10, s);
    	} else {
        	i = 0;
        	if (n < 0) {
            	s[i++] = '-';
        	}
    	}
    	s[i++] = (n < 0 ? - (n % 10) : n % 10) + '0';
    	s[i] = '\0';
}
