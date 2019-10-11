#include <stdio.h>
#include <ctype.h> /* for isdigit(c), etc. */

#define SIZE 100
#define BUFSIZE 100

int getint(int *);

int getch(void);
int main()
{
  	int n = 0 ;
	int c;
	int sign;
  	while((c = getint(&n)) != EOF) {
		if(c == 0){
			c = getch();
			printf("+ or - = %c\n\n", c);
		} else {		
			printf("value n =%d\n", n);
			printf("value n+1 =%d\n", c);  /* %d */
			printf("value n+1 =%c\n\n", c); /* %c */
		}
	}
  	return 0;
}

int getch(void);
void ungetch(int c);
int getint(int *pn)
{
     	int c, sign;    
     	while(isspace(c = getch())){
         	;
     	}
     	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
         	ungetch(c);
         	return 0;
     	}
     	sign = (c == '-') ? -1 : 1;
 	if(c == '+' || c == '-'){
  		c = getch();
 		if(!isdigit(c)){
  			ungetch(c);
			if(sign == 1){
				ungetch('+');
			} else {
				ungetch('-');
			}
			return 0;
     		}
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
