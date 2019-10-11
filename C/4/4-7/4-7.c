#include <stdio.h>
int main()
{
    int c;
    void ungets(char []);
    int getch();
        
    ungets("Hello World\n");
    while ((c = getch()) != '\n') {
        putchar(c);
    }
    putchar('\n');
    return 0;
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
#include <string.h>
void ungets(char s[])
{
    int len;
    
    len = strlen(s);
    while(len > 0)
        ungetch(s[--len]);
}
