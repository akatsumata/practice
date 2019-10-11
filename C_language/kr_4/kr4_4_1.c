#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void top(void);
void dup(void);
void swap(void);
void stack_clear(void);

int main()
{
	int type;
    	double op1, op2;
    	char s[MAXOP];
    
    	while ((type = getop(s)) != EOF){
        	switch (type){
            	case NUMBER:
                	push(atof(s));
                	break;
            	case '+':
                	push(pop() + pop());
                	break;
            	case '*':
                	push(pop() * pop());
                	break;
            	case '-':
                	op2 = pop();
                	push(pop() - op2);
                	break;
            	case '/':
                	op2 = pop();
                	if(op2 != 0.0){
                    		push(pop() / op2);
                	} else {
                    		printf("error: zero divisor\n");
                	}
                	break;
            	case 't':
                	top();
                	break;     
            	case 'd':
                	dup();
                	break;
            	case 'w':
                	swap();
                	break;
            	case 'c':
                	stack_clear();
                	break; 
            	case '\n':
                	printf("\t%.8g\n", pop());
                	break;
            	default:
                	printf("error: unknown command %s\n", s);
                	break;
        	}
    	}
    	return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if(sp < MAXVAL){
        	val[sp++] = f;
    	} else {
        	printf("error: stack full, can't push %g\n", f);
    	}
}

double pop(void)
{
    	if(sp > 0){
        	return val[--sp];
    	} else {
        	printf("error: stack empty\n");
        	return 0.0;
    	}
}

#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{
    	int i, c;
    
    	while ((s[0] = c = getch()) == ' '|| c == '\t'){
        	;
    	}
	s[1] = '\0';
    	if (!isdigit(c) && c != '.' && c != '-') {
        	return c;
    	}
    	i = 0;
    	if(c == '-'){
        	if(isdigit(c = getchar()) || c == '.'){
            		s[++i] = c;
        	} else {
            		if (c != EOF) {
                	ungetch(c);
            		}
            		return '-';
        	}
    	}
    	if(isdigit(c)){
        	while (isdigit(s[++i] = c = getch())){
            		;
    		}
	}
    	if(c == '.'){
        	while (isdigit(s[++i] = c = getch())){
            		;
    		}
	}
    	s[i] = '\0';
    	if(c != EOF){
        	ungetch(c);
    	}
    	return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    	if (bufp >= BUFSIZE) {
        	printf("ungetch: too many characters\n");
    	} else {
        	buf[bufp++] = c;
    	}
}
/* print the top element */
void top(void)
{
	double op1, op2;
 	if(sp > 0){
  		op2 = pop();
  		printf("\t%.8g\n", op2);
 	 	push(op2);
 	} else {
  		printf("error: stack top\n");
 	}
}
/* duplicate the top element */
void dup(void)
{
	double op1, op2;
  	op2 = pop();
  	push(op2);
  	push(op2);
}
/* swap the top two element */
void swap(void)
{
	double op1, op2;
  	op1 = pop();
  	op2 = pop();
  	push(op1);
  	push(op2);
}
/* stack clear */
void stack_clear(void)
{
 	sp = 0;
}
