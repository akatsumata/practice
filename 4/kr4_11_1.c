/* calc .h
 * int getop(char []);
 * void push(double);
 * double pop(void);
 * int getch(void);*/

/* main.c */
#include <stdio.h>
#include <stdlib.h>
/*#include "calc.h"*/
#define MAXOP 100
#define NUMBER '0'
int getop(char []);
void push(double);
double pop(void);
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
/* stack.c */
#include <stdio.h>
/*#include "calc.h"*/
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
/* getop.c */
#include <stdio.h>
#include <ctype.h>
/*#include "calc.h"*/
int getch(void);
int getop(char s[])
{
    int i, c;
    static int before = 0;
    
    if (before == 0) {
        c = getch();
    } else {
        c = before;
        before = 0;
    }
    while ((s[0] = c) == ' '|| c == '\t')
        c = getch();
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                before = c;
            }
            return '-';
        }
    }
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF) {
        before = c;
    }
    return NUMBER;
}


/* getch.c */
#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
