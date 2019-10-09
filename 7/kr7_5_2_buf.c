#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    char c;
   /* if (bufp > 0) {
 *         return buf[--bufp];
 *             } else {
 *                     scanf("%c", &c);
 *                             return c;
 *                                 }*/
    return(bufp > 0) ? buf[--bufp] : scanf("%c", &c);
}
void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
