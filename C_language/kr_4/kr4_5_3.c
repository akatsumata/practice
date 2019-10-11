#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXOP 100
#define NUMBER '0'
#define NAME 'a'
int getop(char[]);
void push(double);
double pop(void);
void clear(void);
void math_h(char[]);
int main() {
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
    if (op2 != 0.0) {
     op2 = pop();
     push(pop() / op2);
    }
    else
     printf("error: zero divisor\n");
    break;
   case 'pow':
    op2 = pop();
    push(pow(pop(), op2));
    break;
   case 'sin':
    push(sin(pop()));
    break;
   case 'exp':
    push(exp(pop()));
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
double val[MAXVAL];
int sp = 0;
void push(double f)
{
    if(sp < MAXVAL){
        val[sp++] = f;
    } else {
        printf("error: stack full, can`t push %g\n", f);
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
 int i, c, j;
 while ((s[0] = c = getch()) == ' ' || c == '\t'){
  ;
 }
 s[1] = '\0';
 if(!isdigit(c) && !isalpha(c) && c != '.' && c != '-')
  return c;
 i = 0;
 if (c == '-')  {
  s[i] = c;
  if (!isdigit(c = getch())) {
   return '-';
  }
  else
   s[++i] = c;
 }
 if (isdigit(c)){
  while (isdigit(s[++i] = c = getch())){
   ;
  }
 }
 if (c == '.'){
  while (isdigit(s[++i] = c = getch())){
   ;
  }
 }
 s[i] = '\0';
 if (c != EOF){
  ungetch(c);
 }
 return NUMBER;
}
#define BUFSIZE 100
char buf[BUFSIZE];  //buffer for ungetch
int bufp = 0; //next free position in buf
int getch(void) // get a (possibly pushed-back) character  
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) // push character back on input
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characnters\n");
    else
        buf[bufp++] = c;
}

void math_h(char s[])
{
    double op2;
    if(strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if(strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if(strcmp(s, "pow")== 0)
        {
            op2 = pop();
            push(pow(pop(), op2));
        }
    else
        printf("error: unknown command %s\n", s);
}

4.9
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
                break;#define MAXVAL 100
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
int getch(void);
void ungetch(int);
int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = getch()) == ' '|| c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }
    i = 0;
    if (c == '-') {
        if (isdigit(c = getchar()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                ungetch(c);
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
        ungetch(c);
    }
    return NUMBER;
}
char buf = 0;
int getch(void)
{
    int c;
    if(buf == 0){
        c = getchar();
    } else {
        c = buf;
    }
    buf = 0;
    return c;    
}
/*int getch(void)
 * {
 *     int c;
 *         c = buf == 0 ? getchar() : buf;
 *             buf = 0;
 *                 return c;
 *                 }*/
void ungetch(int c)
{
    if (buf != 0) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
}

