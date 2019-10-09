#include <stdio.h>
#include <ctype.h> /* for isdigit(c), etc. */

#define SIZE 10
#define BUFSIZE 100

int getint(int *);
int main()
{
  	int n = 0;
	while(getint(&n) != EOF) {
		printf("%d\n", n);
	}
	return 0;
}

int getch(void);
void ungetch(int c);
int getint(int *pn)
{
     	int c, stock, sign;    
     	while(isspace(c = getch())){
         	;
     	}
     	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
         	ungetch(c);
         	return 0;
     	}
     	sign = (c == '-') ? -1 : 1;
 	if(c == '+' || c == '-'){
         	stock = c;
  		c = getch();
 	}
 	if(!isdigit(c) && c != EOF){
  		ungetch(stock);
             	return 0;
     	}
     	for(*pn = 0; isdigit(c); c = getch()){
         	*pn = 10 * *pn + (c - '0');
     	}
     	*pn *= sign;
     	if(c != EOF){
         	ungetch(c);
     	}
     	return c;
}

int bufp = 0;
int buf[BUFSIZE];
int getch(void)
{
  	return bufp > 0 ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
  	if(bufp >= BUFSIZE){
  		printf("ungetch: too many characters\n");
 	} else {
    		buf[bufp++] = c;
 	}
}
