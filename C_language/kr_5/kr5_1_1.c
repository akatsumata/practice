#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
 
int main()
{
 	int x, n;
 	int *pn;
 	x = -1;
 	pn = &x;
 	printf("getint =%d, x =%d\n", getint(pn), x);
 	return 0;
}
 
int getint(int *pn)
{
 	int c1, c2, sign;
 	while(isspace(c1 = getch())){
  		;
 	}
 	if(!isdigit(c1) && c1 != EOF && c1 != '+' && c1 != '-'){
   		ungetch(c1);
   		return 0;
 	}
 	sign = (c1 == '-') ? -1 : 1;
 	if(c1 == '+' || c1 == '-'){
  		c2 = c1;
         	if(!isdigit(c1 = getch())){
   			if(c1 != EOF){
           			ungetch(c1);
   			}
   		ungetch(c2);
   		return c2;
         	}
	} 
 	for(*pn = 0; isdigit(c1); c1 = getch()){
  		*pn = *pn * 10 + (c1 - '0');
 	}
 	*pn *= sign;
 	if(c1 != EOF){
  		ungetch(c1);
 	}
 	return c1;
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
   		printf("error: too many characters\n");
 	} else {
          	buf[bufp++] = c;
        }
}
