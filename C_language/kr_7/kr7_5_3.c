#include <stdio.h>

#define MAXSIZE 100

void push(double);
double pop(void);

int main(void)
{
    	double op1, op2;
    	char c, input;
    	char s[MAXSIZE];
    
	while(scanf("%s%c", s, &input) == 2){
        	if(sscanf(s, "%lf", &op1) == 1){
            		push(op1);
        	} else if(sscanf(s, "%c", &c) == 1) {
            		switch(c){
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
                		if(op2 == 0){
                    			printf("error : zero divisor\n");
                		} else {
                    			push(pop() / op2);
                		}
                		break;
            		default:
                		printf("error : unknown command%s\n", s);
                		break;
            		}
        	}
        	if(input == '\n'){
            		printf("\t%.8g\n", pop());
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
                printf("error : stack full, can't push\n");
        }
}

double pop(void)
{
        if(sp > 0){
                return val[--sp];
        } else {
                printf("error : stack empty\n");
                return 0.0;
        }
}
