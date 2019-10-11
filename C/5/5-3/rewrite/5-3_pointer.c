#include <stdio.h>
#define MAXLINE 100
void pointer_strcat(char *, char *);
int main()
{
        char s[MAXLINE] = "hello", t[MAXLINE] = ", world";
        pointer_strcat(s, t);
        printf("%s\n", s);
        return 0;
}
void pointer_strcat(char *s, char *t)
{
        while(*s != '\0'){
                 s++;
        }
        while((*s = *t) != '\0'){
                s++;
                t++;
        }
}

