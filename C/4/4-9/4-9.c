#include <stdio.h>

int getch(void);
void ungetch(int c);

int main()
{
    	int getch();
    	void ungetch(int);
    	ungetch(EOF);
    	if(getch() == EOF){
        	printf("EOF = -1\n");
    	}
    	return 0;
}

#define BUFSIZE 100
int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    	if(bufp >= BUFSIZE){
        	printf("ungetch: too many characters\n");
    	} else {
        	buf[bufp++] = c;
    	}
}
