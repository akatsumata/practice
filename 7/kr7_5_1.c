#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);

int main()
{
     	double op1, op2;
     	char s[MAXOP], c, d;
     
	while(scanf("%s", s) != EOF){
         	if(sscanf(s, "%lf", &op1) == 1){
              		push(op1);
         	} else if(sscanf(s, "%c", &c) == 1){
              		switch (c){
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
                 	default:
                      		printf("error: unknown command %s\n", s);
                      		break;
              		}
         	}
     	}
     	return 0;
}


#define MAXVAL  100
int sp = 0;
double val[MAXVAL];
void push(double f)
{
     	if(sp < MAXVAL){
        	val[sp++] = f;
     	} else {
        	 printf("error: stack full, can′t push %g\n", f);
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
