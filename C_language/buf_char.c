#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(char *s)
{
    	int len;
    
    	len = strlen(s);
    	while(len > 0){
        	ungetch(s[--len]);
	}
}


