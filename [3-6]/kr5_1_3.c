#include <stdio.h>
#include <ctype.h> /* for isdigit(c), etc. */

#define SIZE 10

int getint(int *);

int main()
{
    	int array[10] = {}, n=0;
      	while(getint(&array[n])!=EOF){
           	array[n++];
                printf("input %d\n\n", array[n-1]);
  	}
 	return 0;
}

int getch(void);
void ungetch(int c);

int getint(int *pn)
{
     	/*int c, sign;*/
     	int c, stock, sign;
    
     	while(isspace(c = getch())){
        	;
     	}
     	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
         	ungetch(c);
         	return 0;
     	}
     	sign = (c == '-') ? -1 : 1;
 	/*if(c == '+' || c == '-'){
         	stock = c;
         	c = getch();
  		if(!isdigit(c)){
              		if(c != EOF){
                  		ungetch(c);
              		}
              		ungetch(stock);
              		return 0;
  		} 
       	}*/
 	if(c == '+' || c == '-'){
           	stock = c;
		if(!isdigit(c)){
			if(c != EOF){
				ungetch(c);
			}
                        ungetch(stock);
                      	return stock;
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
int buf[SIZE];

int getch(void)
{
  	return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  	if(bufp < SIZE){
    		buf[bufp++] = c;
 	}
}
