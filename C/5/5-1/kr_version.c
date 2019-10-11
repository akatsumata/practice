#include <stdio.h>
#include <ctype.h>
#define SIZE 10
int getint(int *);
int getch(void);
void ungetch(int);
int main()
{
        int array[10], n=0;
        while(getint(&array[n])!=EOF) {
                array[n++];
                printf("input_back=%d\n",array[n-1]);
        }
        return 0;
}
#include <ctype.h>
int getch(void);
void ungetch(int);
int getint(int *pn)
{
        int c, sign;
        while(isspace(c = getch())){
                ;
        }
        if(!isdigit(c) && c != EOF && c!= '+' && c != '-'){
                ungetch(c);
                return 0;
        }
        sign = (c == '-') ? -1 : 1;
        if(c == '+' || c == '-'){
                c = getch();
        }
        for(*pn = 0; isdigit(c); c = getch()){
                *pn = *pn * 10 + (c - '0');
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

