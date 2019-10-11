#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100
#define NUMBER '0'
int getop(char []);
void push(double);
double pop(void);
/*void variables1();
void variables2();*/
int main()
{
        int type, i, variable_n;
        double op2, variable[26], u; /* u = a value for the most recently printed value*/
        char s[MAXOP];
        variable_n = 0;
        for(i = 0; i < 26; i++) {
                variable[i] = 0.0;
        }
        while((type = getop(s)) != EOF) {
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
                        if(op2 != 0.0) {
                                push(pop() / op2);
                        } else {
                                printf("error: zero divisor\n");
                        }
                        break;
                case '=':
                        /*variables1();*/
                        if(variable_n >= 'A' && variable_n <= 'Z') {
                                variable[variable_n - 'A'] = pop();
                        } else {
                                printf("error: variable name %c\n", variable_n);
                        }
                        break;
                case '\n':
                        u = pop();
                        printf("\t%.8g\n", u);
                        break;
                default:
                        /*variables2();*/
                        if(type >= 'A' && type <= 'Z'){
                                push(variable[type - 'A']);
                        } else if (type == 'u') {
                                push(u);
                        } else {
                                printf("error: unknown command %s\n", u);
                        }
                        break;
                }
                variable_n = type;
        }
        return 0;
}
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
void push(double f)
{
        if(sp < MAXVAL) {
                val[sp++] = f;
        } else {
                printf("error: stack full, can't push %g\n", f);
        }
}
double pop(void)
{
        if(sp > 0) {
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
        while ((s[0] = c = getch()) == ' '|| c == '\t')
                ;
        s[1] = '\0';
        i = 0;
        if(!isdigit(c) && c != '.' && c != '-') {
                return c;
        }
        if(c == '-') {
                if(isdigit(c = getch()) || c == '.') {
                        s[++i] = c;
                } else {
                        if(c != EOF) {
                                ungetch(c);
                }
                return '-';
                }
        }
        if(isdigit(c)) {
                while(isdigit(s[++i] = c = getch()))
                        ;
        }
        if(c == '.') {
                while (isdigit(s[++i] = c = getch()))
                        ;
        }
        s[i] = '\0';
        if(c != EOF) {
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
        if(bufp >= BUFSIZE) {
                printf("ungetch: too many characters\n");
        } else {
                buf[bufp++] = c;
        }
}
/*
double op2, variable[26], u;
int type, i, variable_n;
void variavles1()
{
        if(variable_n >= 'A' && variable_n <= 'Z') {
                variable[variable_n - 'A'] = pop();
        } else {
                printf("error: variable name %c\n", variable_n);
        }
}*/
/*
void variables2()
{
        if(type >= 'A' && type <= 'Z'){
                push(variable[type - 'A']);
        } else if (type == 'u') {
                push(u);
        } else {
                printf("error: unknown command %s\n", u);
        }
}*/

