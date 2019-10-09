#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
int getop(char []);
void push(double);
double pop(void);
int l_getline(char s[], int lim);

int main()
{
    int type;
    double op2;
    char s[MAXOP];
   
    while ((type = getop(s)) != EOF) {
        switch (type) {
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
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
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
    	if (sp < MAXVAL) {
        	val[sp++] = f;
    	} else {
        	printf("error: stack full, can't push %g\n", f);
    	}
}

double pop(void)
{
    	if (sp > 0) {
        	return val[--sp];
    	} else {
        	printf("error: stack empty\n");
        	return 0.0;
    	}
}

#include <ctype.h>
#define MAXLINE 1000
int l;
char line[MAXLINE];
int l_getline(char [], int);

int getop(char s[])
{
    	int i, c;
    	if(line[l] == '\0') {
        	if(l_getline(line, MAXLINE) == 0) {
            		return EOF;
        	} else {
            		l = 0;
        	}
    	}
    	while ((s[0] = c = line[l++]) == ' '|| c == '\t')
        	;
    	s[1] = '\0';
    	if (!isdigit(c) && c != '.' && c != '-') {
        	return c;
    	}
    	i = 0;
    	if(!isdigit(c) && c != '.'){
      		return c;
    	}
    	i = 0;
    	if(c == '-') {
        	if(isdigit(c = line[l++]) || c == '.') {
            		s[++i] = c;
        	} else {
            		l--;
            		return '-';
        	}
    	}
    	if (isdigit(c)) {
        	while (isdigit(s[++i] = c = line[l]++))
    	        	;
    	}
    	if(c == '.') {
        	while (isdigit(s[++i] = c = line[l++]))
            		;
    	}
    	s[i] = '\0';
    	l--;
    	return NUMBER;
}

int l_getline(char s[], int lim)
{
    	int c, i;
    
    	i = 0;
    	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        	s[i++] = c;
    	}
    	if(c == '\n') {
        	s[i++] = c;
    	}
    	s[i] = '\0';
    	return i;
}
