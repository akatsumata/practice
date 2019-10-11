#include <stdio.h>
#include <string.h>
 
void itob(unsigned n, char s[], int b);
void reverse(char s[]);
 
int main()
{
    	char s[100] = "";
    	unsigned n;
    	int b;
 
    	n = 65535;
    	b = 16;
    	itob(n, s, b);
    	printf("unsigned n =%u, radix b =%d, string s =%s\n", n, b, s);
    	return 0;
}
 
void itob(unsigned n, char s[], int b)
{
    	int i, c;
 
    	i = 0;
    	do{
        	c = n % b;
        	if(c < 10){
            		s[i] = c + '0';
            		++i;
        	} else {
            		s[i] = c + 'A' - 10;
            		++i;
        	}
    	} while((n /= b) > 0);
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

